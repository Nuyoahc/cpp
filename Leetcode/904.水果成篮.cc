// Leetcode 904. 水果成篮
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int count = 0;
        int hash[10001] = {0};
        int res = 0;
        for (int left = 0, right = 0; right < fruits.size(); right++)
        {
            if (hash[fruits[right]]++ == 0)
                count++;

            while (count > 2)
            {
                if (--hash[fruits[left]] == 0)
                    count--;

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
    vector<int> fruits = {1, 2, 1};
    int result = solution.totalFruit(fruits);
    // Output the result
    cout << "The maximum number of fruits in two baskets is: " << result << endl;
    return 0;
}