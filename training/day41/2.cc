// https://ac.nowcoder.com/acm/problem/213484
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
long long a[N];
long long dp[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    // dp[i]：[1, i] 区间内的最大饱食度
    // 选 i 位置：dp[i - 3] + a[i - 1]
    // 不选 i 位置：dp[i - 1]
    // 返回：dp[n]
    for(int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 3] + a[i - 1]);
    }
    cout << dp[n] << endl;
    
    return 0;
}