class Solution {
private:
    vector<vector<int>> res;
   // map<int, bool> used;
   // vector<int> track;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used;
        used.resize(nums.size());
        vector<int> track;
        backtrack(nums, used, track);
        return res;

    }
    void backtrack(vector<int>& nums, vector<bool> used, vector<int> track){
        // base case
        if (track.size() == nums.size()){
            res.push_back(track);
            return;
        }
        for (int i = 0;i < nums.size(); ++i){
            // 排除不合法的选择
            if (used[i]){
                // nums[i] 已经在 track 中，跳过
                continue;
            }
            // 前序位置
            // 做选择
            used[i] = true;
            track.push_back(nums[i]);
            // 进入下一层决策树
            backtrack(nums, used, track);
            // 后序位置
            // 撤销选择
            track.pop_back();
            used[i] = false;
        }
    }
};

