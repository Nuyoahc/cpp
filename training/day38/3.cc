// https://www.nowcoder.com/practice/6a7b2b6c9e3a4f56b1db9f8ca08d889b?tpId=230&tqId=38958&ru=/exam/oj
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1010;
int n, k;
LL a[N];
LL dp[N][N];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
        
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - a[i] % k + k) % k] + a[i]);
        }
    }
    if (dp[n][0] <= 0)
        cout << -1 << endl;
    else
        cout << dp[n][0] << endl;
    return 0;
}