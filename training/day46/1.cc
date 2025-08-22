#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int n, x;
int arr[N];
int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    long long ret = 0;
    int index = max(0, n - x); // 处理 x 过⼤的情况
    ret += arr[index] * x;
    for (int i = index + 1; i <= n; i++)
        ret += arr[i] - arr[index];
    cout << ret << endl;
    return 0;
}