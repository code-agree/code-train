#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    vector<bool> visited;
    vector<bool> onPath;
    vector<int> postorder;
    bool hasCycle = false;
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        visited.resize(numCourses, false);
        // onPath.resize(numCourses);
        vector<vector<int>> graph = buildGraph(prerequisites,numCourses);
        for (int i = 0; i < numCourses; ++i){
            dfs(graph, i);
        }
        if (hasCycle){
            return {};
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }

    void dfs(vector<vector<int>>& graph, int s){
        if (onPath[s]){
            hasCycle = true;
        }
        if (visited[s] || hasCycle){
            return;
        }
        visited[s] = true;
        onPath[s] = true;
        for (int i : graph[s]){
            dfs(graph, i);
        }
        postorder.push_back(s);
        onPath[s] = false;
    };

    vector<vector<int>> buildGraph(vector<vector<int>>& prerequisites, int numCourses){
        vector<vector<int>> graph(numCourses);
        for (auto vec : prerequisites){
            int from = vec[1];
            int to = vec[0];
            graph[from].push_back(to);
        }
        return graph; 
    }
};


int main(){
    Solution so;
    vector<vector<int>> pre = {{1, 0}}; 
    vector<int>  res = so.findOrder(2, pre);
    for (auto i : res){
        cout << i << endl;
    }
    // vector<bool> visited2(4, false);
}