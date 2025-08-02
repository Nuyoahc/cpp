// https://www.nowcoder.com/practice/a2be806a0e5747a088670f5dc62cfa1e?tpId=230&tqId=39763&ru=/exam/oj
#include <iostream>
using namespace std;

const int N = 10e5 + 10;
int dp[N]; // dp[i]表示前i个不相邻数的最大和
int a[N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[1] = a[1];
    dp[2] = max(a[1], a[2]);
    for(int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }

    cout << dp[n] << endl;

    return 0;
}