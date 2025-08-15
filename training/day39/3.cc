// https://www.nowcoder.com/practice/4b2f5d4c00f44a92845bdad633965c04?tpId=230&tqId=40431&ru=/exam/oj
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e4 + 10;
int dp[N];
int n;

int main()
{   
    // dp[i][j]表示：从前i个数中挑选（1 2 4 9 16...），恰好为j时，最少挑选出几个数
    // 状态转移方程：
    // 不选第i个数，dp[i][j] = dp[i - 1][j]
    // 选第i个数1个，dp[i][j] = dp[i - 1][j - i * i] + 1
    // 选第i个数2个，dp[i][j] = dp[i - 1][j - 2 * i * i] + 2
    // ...
    // 所有选的可能，dp[i][j] = dp[i][j - i * i] + 1
    cin >> n;

    memset(dp, 0x3f, sizeof dp);

    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i * i; j <= n; j++)
        {
            dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
    }

    cout << dp[n] << endl;


    return 0;
}