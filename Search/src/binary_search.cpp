#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    // 二分查找
    int binary_search(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid + 1;
            if(nums[mid] > target) right = mid - 1;
            if(nums[mid] == target) return mid;
        }
        return left;
    }
};

int main(){
    vector<int> nums = {1, 3, 5, 7, 9, 10, 11, 19};
    Solution s;
    cout << s.binary_search(nums, 20) << endl;
    return 0;
}