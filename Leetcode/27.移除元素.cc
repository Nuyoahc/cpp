#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> res;
        for(auto &e : nums)
        {
            if(e != val) res.push_back(e);
        }
        nums = res;
        return nums.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int newSize = sol.removeElement(nums, val);
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}