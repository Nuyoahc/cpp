// https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&tqId=21275&ru=/exam/oj
#include <iostream>
#include <string>
using namespace std;
const int N = 1010;
string a, b;
int dp[N][N];
int main()
{
    cin >> a >> b;
    int n = a.size(), m = b.size();
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j -
                                                                          1]) +
                           1;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}