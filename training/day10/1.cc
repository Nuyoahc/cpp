// https://www.nowcoder.com/practice/b4525d1d84934cf280439aeecc36f4af?tpId=182&tqId=34752&ru=/exam/oj
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A string字符串 
     * @return int整型
     */
    int getLongestPalindrome(string A) {
        // write code here
        int n = A.size();
        if (n == 0) return 0;
        
        int len = 0;
        for(int i = 0; i < n; i++)
        {
            int l = i, r = i;
            while (l >= 0 && r < n && A[l] == A[r])
            {
                l--;
                r++;
            }
            len = max(len, r - l - 1);

            l = i, r = i + 1;
            while (l >= 0 && r < n && A[l] == A[r])
            {
                l--;
                r++;
            }
            len = max(len, r - l - 1);
        }
        return len;
    }
};

int main() {
    Solution solution;
    string A = "ababa";
    cout << solution.getLongestPalindrome(A) << endl; // Output: 5
    return 0;
}