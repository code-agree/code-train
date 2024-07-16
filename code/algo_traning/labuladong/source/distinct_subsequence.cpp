#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> memo;
public:
    int numDistinct(string s, string t) {
        memo.resize(s.size(), vector<int>(t.length(), -1));
        int res = dp(s, 0, t, 0);
        return res;
    }
    // definition of dp s[i...] 中出现t[j...]的次数
    int dp(string& s, int i, string& t, int j){
        // base case
        if (j == t.size()){
            return 1;
        }
        if (s.size() - i < t.size() - j){
            return 0;
        }
        if (memo[i][j] != -1){
            return memo[i][j];
        }
        int res = 0;
        for (int k = i; k < s.size(); ++k ){
            if (s[k] == t[j]){
                res += dp(s, k + 1, t, j + 1);
            }
        }
        memo[i][j] = res;
        return res;
    }
};