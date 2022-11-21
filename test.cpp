class Solution {
private:
    vector<bool> visited;
    // 记录一次递归堆栈中的节点
    vector<bool> onPath;
    bool hascycle;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildgraph(numCourses, prerequisites);
        for (int i = 0; i < numCourses; ++i){
            traverse(graph, i);
        }
        return !hascycle;
    }
    vector<vector<int>> buildgraph(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph;
        graph.resize(numCourses);
        for (vector<int> edge : prerequisites){
            int from = edge[1], to = edge[0];
            graph[from].push_back(to);
        }
        return graph;
    }
    void traverse(vector<vector<int>> graph, int s){
        //这里为什么是onPath做判断而不是visited ？
        // onPath会动态维护、记录当前路径，visited只会记录是否访问过；
        if (onPath[s]){
            hascycle = true;
        }
        if (visited[s] || hascycle){
            return;
        }
        visited[s] = true;
        onPath[s] = true;
        for (int t : graph[s]){
            traverse(graph, t);
        }
        onPath[s] = false;
    }
};