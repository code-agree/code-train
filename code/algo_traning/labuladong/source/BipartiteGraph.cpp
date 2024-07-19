#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    vector<bool> visited;
    vector<int> colour;
    bool isBip = true;

public:
    bool isBipartite(vector<vector<int>>& graph) {
        visited.resize(graph.size());
        colour.resize(graph.size());
        // for (int i = 0; i < graph.size(); ++i){
        traverse(graph, 0);
        // }
        return isBip;
    }
    // dfs
    void traverse(vector<vector<int>>& graph, int s){
        // first
        if (!isBip){
            return;
        }
        visited[s] = true;
        for (int node : graph[s]){
            if (!visited[node]){
                colour[s] = 1;
                traverse(graph, node);
            }
            else{
                // not 
                if (colour[s] == colour[node]){
                    isBip = false;
                    return;
                }
            }
        }
    }
};

int main(){
    Solution so;
    vector<vector<int>> graph = {{1,2},{0,2},{0,1}};
    bool res =so.isBipartite(graph);
    cout << res << endl;
}