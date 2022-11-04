class Solution {
private:
    vector<int> diff;
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>nums;
        nums.resize(1001);
        Difference df = new Difference(nums);
        // 构造差分数组
        for (int trip : trips){
            int val = trip[0];
            int j = trip[1];
            int j = trip[2] - 1;
            df.increment(i, j, val);
        }
    vector<int> res = df.result();
    for (int i = 0; i < res.size(); ++i){
        if (capacity < res[i]){
            return false;
        }
    }
    return true;
    }
}
// 差分数组工具类
class Difference {
    // 差分数组
    private vector<int>diff;
    
    /* 输入一个初始数组，区间操作将在这个数组上进行 */
    public Difference(vector<int> nums) {
        assert nums.size() > 0;
        diff.resize(nums.size());
        // 根据初始数组构造差分数组
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    /* 给闭区间 [i, j] 增加 val（可以是负数）*/
    public void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }

    /* 返回结果数组 */
    public vector<int> result() {
        vector<int>res;
        res.resize(diff.size())
        // 根据差分数组构造结果数组
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};