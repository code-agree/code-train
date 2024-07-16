#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtrack(nums, 0);
        return res;
    }
    void backtrack(vector<int>& nums,int start){
        // cout << "step 1  " << nums[start] << endl;
        res.push_back(path);
        // cout << "step 2 for " << nums[start] << endl;
        for (int i = start; i < nums.size(); i++){
            cout << "for  " << i << endl;
            // cout << "step 3 push back" << i << endl;
            path.push_back(nums[i]);
            cout << "step 4 into backtrack" << (i + 1) << endl;
            backtrack(nums, i + 1);
            cout << "step 5 out backtrack and pop" << (i + 1) << endl;
            path.pop_back();

        }
    }
};


int main() {
    Solution solver;
    vector<int> vec = {1, 2, 3};
    vector<vector<int>> res = solver.subsets(vec);
    for (const vector<int>& vec : res ){
        for (auto it = vec.begin(); it != vec.end(); ++ it) 
        {
            cout << *it << "\n";
        }
    }
    return 0;
}