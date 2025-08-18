// https://www.nowcoder.com/practice/67b93e5d5b85442eb950b89c8b77bc72?tpId=230&tqId=40432&ru=/exam/oj
#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010;
const int M = 5010;

int a[N];
int dp[M];
int n, aim;

int main()
{
    cin >> n >> aim;
    for(int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, 0x3f, sizeof dp);
    // dp[i][j]：从前i个纸币中挑选，正好总和为j，此时的最少张数  
    // 不选a[i]：dp[i][j] = dp[i - 1][j]
    // 选1个a[i]  ：dp[i][j] = dp[i - 1][j - a[i]] + 1
    // 选2个a[i]  : dp[i][j] = dp[i - 1][j - 2 * a[i]] + 2
    // ...
    // dp[i][j] = dp[i][j - a[i]] + 1

    // dp[i][j] = min(dp[i - 1][j], dp[i][j - a[i]] + 1)
    dp[0] = 0; // 0张纸币凑成0元
    for(int i = 1; i <= n; i++)
    {
        for(int j = a[i]; j <= aim; j++)
        {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }
    if(dp[aim] >= 0x3f) cout << -1 << endl;
    else cout << dp[aim] << endl;

    return 0;
}