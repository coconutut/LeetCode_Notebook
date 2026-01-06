#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
public:
    int linear_search(vector<int>& nums, int target){
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == target) return i;
            else if(nums[i] < target && nums[i + 1] > target){
                return i;
            }
        }
        return nums.size();
    }
};

int main(){
    vector<int> nums = {1, 3, 5, 7, 9, 10, 11, 19};
    Solution s;
    cout << s.linear_search(nums, 20) << endl;
    return 0;
}