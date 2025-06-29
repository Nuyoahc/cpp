#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int res = INT_MAX;

        int sum = 0;
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int result = solution.minSubArrayLen(target, nums);
    // Output the result
    std::cout << "The length of the smallest subarray with sum >= " << target << " is: " << result << std::endl;
    return 0;
}