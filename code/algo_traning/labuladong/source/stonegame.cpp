#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        // 创建一个二维数组来存储每个子问题的结果
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // 初始化：当只有一堆石子时，直接拿走这堆石子
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        
        // 逐步解决更大的子问题
        // 外层循环 len 控制我们正在考虑的石子堆的长度，从 2 开始，最大到 n
        for (int len = 2; len <= n; len++) {
            for (int i = len; i <= n; i++) {
                int j = i + len - 1;
                
                // 选择左边的石子堆
                int chooseLeft = piles[i] - dp[i+1][j];
                
                // 选择右边的石子堆
                int chooseRight = piles[j] - dp[i][j-1];
                
                // 取两种选择中的较大值
                dp[i][j] = max(chooseLeft, chooseRight);
            }
        }
        
        // 如果最终结果大于0，则Alice赢
        return dp[0][n-1] > 0;
    }
};