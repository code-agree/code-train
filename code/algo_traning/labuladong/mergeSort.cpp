#include <iostream>
#include <vector>

using namespace std;

class merge_solution{
private:
    vector<int> temp;
public:
    void sort(vector<int>& nums){
        temp.resize(nums.size());
        sort(nums, 0, nums.size() - 1);
    }
    void sort(vector<int>& nums, int lo, int hi){
        if (lo == hi){
            return;
        }
        int mid = lo + (hi - lo )/2;
        sort(nums, lo, mid);
        sort(nums, mid + 1, hi);
        merge(nums, lo, mid , hi);
    }
    void merge(vector<int>& nums, int lo, int mid, int hi){
        for (int i = lo; i <= hi; ++i){
            temp[i] = nums[i];
        }
        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p++){
            if (i == mid + 1){
                nums[p] = temp[j++];
            }
            else if (j == hi + 1){
                nums[p] = temp[i++];
            } 
            else if (temp[i] > temp[j]){
                //nums[p] = temp[j];
                //j++;
                nums[p] = temp[j++];
            }
            else{
                nums[p] = temp[i++];
            }
        }
    }
};

int main(){
    merge_solution mergesort;
    vector<int> arr = {10, 7777, 5, 41, 4, 1, 2, 9, 7, 19};
    for (int n : arr) cout << n << " ";
    cout << endl;

    mergesort.sort(arr);

    for (int n : arr) cout << n << " ";
    cout << endl;
}