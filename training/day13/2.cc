#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        int res = 0;
        int left = 0, right;
        int hash[100001] = {0};
        while(right < arr.size())
        {
            hash[arr[right]]++;
            while(hash[arr[right]] > 1)
            {
                hash[arr[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};

int main()  
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    Solution sol;
    cout << sol.maxLength(arr) << endl;
    
    return 0;
}