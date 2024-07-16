#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int step;
        // unordered_set<string> deads;
        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        // int step = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; ++i){
                string cur = q.front();
                q.pop();
                // isArrive ?
                if (deadends.count(cur)){
                    continue;
                }
                if (cur == target){
                    return step;
                }
                for (int j = 0; j < 4; ++j){
                    string up = plusNums(cur,j);
                    if (!visited.count(up)){
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = minusNums(cur,j);
                    if (!visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    string plusNums(string s, int i){
        if (s[i] == '9'){
            s[i] = 0;
        }
        else{
            s[i] += 1;
        }
        string res = s; 
        return res;
    }
    string minusNums(string s, int i){
        if (s[i] == '0'){
            s[i] = '9';
        }
        else{
            s[i] -= 1;
        }
        string res = s; 
        return res;
    }
};


int main(){
    Solution so;
    vector<string> deads = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    int res = so.openLock(deads, target);
    cout << res << endl;
}