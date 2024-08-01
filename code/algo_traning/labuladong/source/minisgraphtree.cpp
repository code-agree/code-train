
#include <iostream>
#include <vector>
#include <string>
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

class Solution{
public:
    int minimumCost(int n, vector<vector<int>>& connections){
        UnionFind UF(n);
        int mst = 0;
        sort(connections.begin(), connections.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            });
        for (auto vec : connections){
            int u = vec[0] - 1;
            int v = vec[1] - 1;
            int weight = vec[2];
            if (UF.isConnect(u, v)){
                continue;
            }
            UF._union(u, v);
            mst += weight;
        }
        return UF.getCount() == 1 ? mst : -1;
    }

};



int main(){
    Solution so;
    int n = 3; 
    vector<vector<int>> connections = {{1,2,5},{1,3,6},{2,3,1}};
    int res = so.minimumCost(n, connections);
    cout << res << endl;
}