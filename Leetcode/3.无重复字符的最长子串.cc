#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
// Leetcode 3. 无重复字符的最长子串
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int hash[128] = {0};
        int res = INT_MIN;
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            hash[s[right] - '0']++;
            while (hash[s[right] - '0'] > 1)
            {
                hash[s[left] - '0']--;
                left++;
            }
            res = max(res, right - left + 1);
        }

        return res;
    }
};

int main()
{
    Solution solution;
    string s = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(s);
    // Output the result
    std::cout << "The length of the longest substring without repeating characters is: " << result << std::endl;
    return 0;
}   