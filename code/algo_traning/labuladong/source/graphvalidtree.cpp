#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Unionfind{
private:
    int count;
    vector<int> parent;
public:
    Unionfind(int n){
        this->count = n;
        parent.resize(n);
        for (int i = 0; i < n; ++i){
            parent[i] = i;
        }
    }

    bool isconnect(int p, int q){
        int P = find(p);
        int Q = find(q);
        return P == Q;
    }

    int find(int x){
        if (x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void _union(int p, int q){
        int P = find(p);
        int Q = find(q);
        if (P == Q){
            return;
        }
        parent[P] = Q;
        count--;
    }

    int getCount(){
        return count;
    }

}