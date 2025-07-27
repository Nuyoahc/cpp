// https://ac.nowcoder.com/acm/problem/223985
#include <iostream>
using namespace std;

int a, h, b, k;
int res;

int main()
{
    cin >> a >> h >> b >> k;
    int n = min(k / a, h / b);
    res += n * (a + b);

    h -= n * b;
    k -= n * a;

    if (h > 0 && k > 0)
    {
        res += a + b;
        // 这次减完后必然至少有一方死亡
        h -= b;
        k -= a;
    }

    if (h > 0 || k > 0)
    {
        res += 10 * (h > 0 ? a : b);
    }

    cout << res << endl;

    return 0;
}