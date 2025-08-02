// https://ac.nowcoder.com/acm/problem/229310
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10e6 + 10;
int a[N];
int n, p;

int main()
{
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    int ret = 0, left = 0, right = 0;
    p *= 2;
    while (right < n)
    {
        while (a[right] - a[left] > p)
        {
            left++;
        }
        ret = max(ret, right - left + 1);
        right++;
    }
    cout << ret << endl;

    return 0;
}
