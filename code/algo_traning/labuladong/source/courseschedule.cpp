#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    bool res = false;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses, false);
        // buildGraph(prerequisites, numCourses);
        for (int i = 0 ;i < numCourses; ++i){
            res = dfs(graph, i);
        }
        return res;
    }
    // void buildGraph(vector<vector<int>>& prerequisites, int numCourses){
    //     graph.resize(numCourses);
    //     for (auto course : prerequisites){
    //         int first = course[1];
    //         int end = course[0];
    //         graph[first].push_back(end);
    //     }
    // }
    bool dfs(vector<vector<int>>& graph, int course){
        
        // 考虑这样的课程依赖：A -> B, C -> B。当我们从C开始DFS时，即使B已经在之前（从A开始的DFS）被访问过，也不意味着存在环。
        if (visited[course]){
            return false;
        }
        visited[course] = true;
        for (int i : graph[course]){
            dfs(graph, i);
        }
        visited[course] = false;
    };
};

bool dfs2(vector<vector<int>>& graph, int course, vector<bool>& visited2){
        
        // 考虑这样的课程依赖：A -> B, C -> B。当我们从C开始DFS时，即使B已经在之前（从A开始的DFS）被访问过，也不意味着存在环。
        if (visited2[course]){
            cout << "has cycle" << endl;
            return false;
        }
        visited2[course] = true;
        for (int i : graph[course]){
            dfs2(graph, i, visited2);
        }
        visited2[course] = false;
    };

int main(){
    // Solution so;
    // vector<vector<int>> pre = {{}, {2, 3}, {4}, {4}}; 
    // bool res = so.canFinish(4, pre);
    vector<bool> visited2(4, false);
    vector<vector<int>> graph = {
    {1, 2}, // 0 连接到 1 和 2
    {3},    // 1 连接到 3
    {3},    // 2 连接到 3
    {}      // 3 没有出边
    };
    for (int i; i < 4; ++i){
        bool red = dfs2(graph, i, visited2);
    }
    // cout << res << endl;
    return 0;
}



class Solution {
private:
    vector<bool> visited;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        visited.resize(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(graph, i)) {
                return false;  // 存在环，无法完成所有课程
            }
        }
        return true;  // 不存在环，可以完成所有课程
    }

private:
    bool hasCycle(const vector<vector<int>>& graph, int course) {
        if (visited[course]) return true;  // 检测到环

        visited[course] = true;

        for (int next : graph[course]) {
            if (hasCycle(graph, next)) {
                return true;  // 在子节点中检测到环
            }
        }
        visited[course] = false;  // 回溯
        return false;
    }
};