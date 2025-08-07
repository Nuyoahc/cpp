// https://www.nowcoder.com/practice/adf828f399de4932955734a4eac12757?tpId=230&tqId=38956&ru=/exam/oj
#include <iostream>
using namespace std;

const int N = 20, M = N * 9;
long long x;
int n, sum; // 这个数有多少位
int arr[N];
bool dp[M];

bool func()
{
    if (sum % 2 == 1)
        return false;
    sum /= 2;
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= arr[i]; j--)
        {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    return dp[sum];
}
int main()
{
    cin >> x;
    while (x)
    {
        arr[n++] = x % 10;
        sum += x % 10;
        x /= 10;
    }
    if (func())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}