// https://www.nowcoder.com/practice/82297b13eebe4a0981dbfa53dfb181fa?tpId=230&tqId=39762&ru=/exam/oj
#include <iostream>
#include <string>
using namespace std;

int dp[1010][1010];

int main()
{
    string s;
    cin >> s;
// **状态表示：**
//    ```dp[i][j]：```表示以```(i, j)```内的最长回文子序列长度
//    **状态转移方程:**
//    - 当```i == j```时，长度为```1```；
//    - 当```i <  j```时，
//       - ```s[i] == s[j]：dp[i][j] = dp[i + 1][j - 1];```
//       -	```s[i] != s[j]：dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);```

// **填表顺序：** 填```(i, j)```位置时，需要```i + 1 和 j - 1```位置，所以从下往上，从左往右；
// **返回值：**```dp[0][n - 1]```
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;

    return 0;
}
