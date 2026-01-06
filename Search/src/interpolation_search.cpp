#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    // 插值查找
    int interpolation_search(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) * (target - nums[left]) / (nums[right] - nums[left]);
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else return mid;
        }
        return left;
    }
};

int main(){
    vector<int> nums = {1, 3, 5, 7, 9, 10, 11, 19, 20, 22, 24};
    Solution s;
    cout << s.interpolation_search(nums, 20) << endl;
    return 0;
}