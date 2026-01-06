#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    unordered_map<int, int> ump;
    int hash_search(vector<int> nums, int target){
        int i = 0;
        for(const int& p : nums){
            ump.insert({p, i});
            i++;
        }
        if(ump.find(target) == ump.end()) return nums.size();
        else return ump[target];
    }
};

int main(){
    vector<int> nums = {1, 3, 5, 7, 9, 10, 11, 19};
    Solution s;
    cout << s.hash_search(nums, 11) << endl;
    return 0;
}