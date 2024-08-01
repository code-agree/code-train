#include<string>
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class UnionFind{
private:
    int count;
    vector<int> parent;
public:
    UnionFind(int n) : count(n), parent(n) {
        for (int i = 0; i < n; ++i){
            parent[i] = i;
        }
    }
    int find(int x){
        if (x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool isConnect(int p, int q){
        int rootp = find(p);
        int rootq = find(q);
        return rootp == rootq;
    }
    void _union(int p, int q){
        int rootp = find(p);
        int rootq = find(q);
        if (rootp == rootq){
            return;
        }
        parent[rootp] = rootq;
        count--;
    }
    int getCount(){
        return count;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int mst = 0;
        int sz = points.size();
        vector<vector<int>> edges;
        UnionFind UF(sz);
        for (int i = 0; i < sz; ++i){
            for (int j = i + 1; j < sz; ++j){
                int xi = points[i][0], yi = points[i][1];
                int ji = points[j][0], jy = points[j][1];
                int weight = abs(xi - ji) + abs(yi - jy);
                edges.push_back({i, j, weight});
            }
        }
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){return a[2] < b[2];});
        for (auto vec : edges){
            int u = vec[0], v = vec[1], wei = vec[2];
            if (UF.isConnect(u, v)){
                continue;
            }
            UF._union(u, v);
            mst += wei;
        }
        return UF.getCount() == 1 ? mst : -1;
    }
};

int main(){
    Solution so;
    int n = 3; 
    vector<vector<int>> connections = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int res = so.minCostConnectPoints(connections);
    cout << res << endl;
}