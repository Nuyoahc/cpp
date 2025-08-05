// https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
// 牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。
// 牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
// 如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int ans = 0, i = 0;
    while (i < n)
    {
        if (i == n - 1)
        {
            ans++;
            break;
        }
        if (a[i] < a[i + 1])
        {
            while (i + 1 < n && a[i] <= a[i + 1])
                i++;
            ans++;
        }
        else if (a[i] > a[i + 1])
        {
            while (i + 1 < n && a[i] >= a[i + 1])
                i++;
            ans++;
        }
        else
        {
            while (i + 1 < n && a[i] == a[i + 1])
                i++;
        }
        i++;
    }

    cout << ans << endl;
    return 0;
}