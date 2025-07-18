#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int p = 0, q = 1;
        while (q < nums.size())
        {
            if (nums[p] == nums[q]) q++;
            else
            {
                nums[p + 1] = nums[q];
                p++, q++;
            }
        }
        return p + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2};
    int newSize = sol.removeDuplicates(nums);
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}