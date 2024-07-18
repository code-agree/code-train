#include<string>
#include<iostream>
#include<vector>

using namespace std;



class Solution {
private:
    vector<vector<int>> res;
    vector<int> onpath;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        traverse(graph, 0);
        return res;
    }
    void traverse(vector<vector<int>>& graph, int s){
        if (graph.size() == 0){
            return
        };
        onpath.push_back(s);
        if (s == graph.size() - 1){
            res.push_back(onpath);
        }
        for (int i : graph[s]){
            traverse(graph,i);
        };
        onpath.pop_back();
    }
};