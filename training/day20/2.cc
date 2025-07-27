// https://www.nowcoder.com/practice/1718131e719746e9a56fb29c40cc8f95?tpId=230&tqId=39753&ru=/exam/oj

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // dp[i]：i 位置之前的子数组最大和
    vector<int> dp(n);
    int res = INT_MAX;
    dp[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1], 0)+ a[i];
        res = max(res, dp[i]);
    }
    cout << res << endl;

    return 0;
}