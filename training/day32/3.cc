// https://www.nowcoder.com/practice/661c49118ca241909add3a11c96408c8?tpId=122&tqId=33652&ru=/exam/oj
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long maxProduct(vector<int> &a, int n, int k, int d)
{
    vector<vector<long long>> max_dp(n + 1, vector<long long>(k + 1, LLONG_MIN));
    vector<vector<long long>> min_dp(n + 1, vector<long long>(k + 1, LLONG_MAX));

    // 初始化：只选1个学生的情况
    for (int i = 1; i <= n; ++i)
    {
        max_dp[i][1] = a[i - 1];
        min_dp[i][1] = a[i - 1];
    }

    for (int j = 2; j <= k; ++j)
    {
        for (int i = j; i <= n; ++i)
        {
            // 检查前d个位置
            for (int m = max(i - d, j - 1); m < i; ++m)
            {
                long long temp1 = max_dp[m][j - 1] * a[i - 1];
                long long temp2 = min_dp[m][j - 1] * a[i - 1];

                max_dp[i][j] = max(max_dp[i][j], max(temp1, temp2));
                min_dp[i][j] = min(min_dp[i][j], min(temp1, temp2));
            }
        }
    }

    long long result = LLONG_MIN;
    for (int i = k; i <= n; ++i)
    {
        result = max(result, max_dp[i][k]);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int k, d;
    cin >> k >> d;

    cout << maxProduct(a, n, k, d) << endl;
    return 0;
}