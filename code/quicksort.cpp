#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // random_device rd;
        // mt19937 g(rd());
        // shuffle(nums.begin(), nums.end(), g);
        sort(nums, 0, n - 1);
        return nums;
    }
    void sort(vector<int>& nums, int lo, int hi){
        if (lo > hi){
            return;
        }
        int p = partition(nums, lo, hi);
        sort(nums, lo, p - 1);
        sort(nums, p + 1, hi);
    }
    int partition(vector<int>& nums, int lo, int hi){
        int pivot = nums[lo];
        int i = lo + 1, j = hi;
        while (i <= j){
            while (i < hi && nums[i] <= pivot){
                ++i;
            }
            while (j > lo && nums[j] > pivot){
                --j;
            }
            if (i >= j){
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[lo], nums[j]);
        return j;
    }
};
// 测试
int main() {
    Solution quicksort;
    vector<int> arr = {10, 7, 5, 41, 4, 1, 2, 9, 7, 10};
    for (int n : arr) cout << n << " ";
    cout << endl;

    quicksort.sortArray(arr);

    for (int n : arr) cout << n << " ";
    cout << endl;
}
