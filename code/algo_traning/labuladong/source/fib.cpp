#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int fib(int n) {
        // base case
        // dp table
        if (n == 0){
            return 0;
        }
        vector<int> dp(n+1, 0);
        dp[0] = 0, dp[1] = 1;
        // if (dp[n] != 0){
        //     return dp[n];
        // }
        for (int i = 2; i <= n; i++){
            dp[n] = dp[n - 1] + dp[n - 2];
        }
        return dp[n];
    }
};

int main(){
    Solution so;
    int res = so.fib(3);
    cout << res << endl;
}