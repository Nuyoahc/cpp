#include <iostream>
using namespace std;
int n, m, x, y;
long long dp[25][25];
int main()
{
    cin >> n >> m >> x >> y;
    x += 1;
    y += 1;
    dp[0][1] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            if (i != x && j != y && abs(i - x) + abs(j - y) == 3 || (i == x && j == y))
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[n + 1][m + 1] << endl;
    return 0;
}