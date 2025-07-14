// https://www.nowcoder.com/practice/9740ce2df0a04399a5ade1927d34c1e1?tpId=230&tqId=38954&ru=/exam/oj
#include <iostream>
using namespace std;
const int N = 510;
char g[N][N];
int dp[N][N];
int m, n;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t = 0;
            if (g[i][j] == 'l')
                t = 4;
            else if (g[i][j] == 'o')
                t = 3;
            else if (g[i][j] == 'v')
                t = 2;
            else if (g[i][j] == 'e')
                t = 1;
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + t;
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}