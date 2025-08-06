// https://www.nowcoder.com/practice/672ab5e541c64e4b9d11f66011059498?tpId=230&tqId=39761&ru=/exam/oj
#include <iostream>
using namespace std;

const int N = 1010;
char s1[N], s2[N];
int dp[N][N];

int main() 
{   
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s1[i];
    for(int i = 1; i <= m; i++) cin >> s2[i];

    // dp[i][j] -> s1区间[0, i] 和 s2区间[0, j]的最长公共子序列
    // s1[i] == s2[j] -> dp[i][j] = dp[i - 1][j - 1] + 1;
    // s1[i] != s2[j] -> dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i] == s2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else 
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[n][m] << endl;
    
    return 0;
}
// 64 位输出请用 printf("%lld")