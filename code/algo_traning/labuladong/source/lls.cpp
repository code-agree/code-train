#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        // base case
        for (int i = 0; i < nums.size();++i){
            for (int j = 0; j < i; ++j){
                if (nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < dp.size();++i){
            res = max(res, dp[i]);
            cout << dp[i] << endl;
        }
        return res;
    }
};

int main(){
    Solution so;
    vector<int> nums = {10,9,2,5,3,7,101,18, 2, 3, 3, 1};
    int res = so.lengthOfLIS(nums);
    cout << res << endl;
}