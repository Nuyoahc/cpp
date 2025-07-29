// https://ac.nowcoder.com/acm/problem/16693
#include <iostream>
using namespace std;
const int N = 35, M = 2e4 + 10;
int n, v;
int arr[N];
int dp[N][M];

int main()
{
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i]] + arr[i]);
            }
        }
    }
    cout << (v - dp[n][v]) << endl;

    return 0;
}