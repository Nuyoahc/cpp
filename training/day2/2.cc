// 爬楼梯问题
// Leetcode 70. 爬楼梯
#include <iostream>
#include <vector>
#include <algorithm> // 用于min函数
using namespace std;

int main() 
{
    int n = 0;
    cin >> n;
    
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> cost(n);
    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    
    cout << dp[n] << endl;

    return 0;
}