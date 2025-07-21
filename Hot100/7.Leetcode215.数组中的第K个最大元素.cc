#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        // priority_queue<int> q(nums.begin(), nums.end());

        // while(--k)
        // {
        //     q.pop();
        // }
        // return q.top();
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = solution.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}