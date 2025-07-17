// https://ac.nowcoder.com/acm/problem/255193

#include <iostream>
using namespace std;
long long n, m, a, b;
int main()
{
    cin >> n >> m >> a >> b;
    long long ret = 0;
    for (long long x = 0; x <= min(n / 2, m); x++) // 枚举 1 号礼包的个数
    {
        long long y = min(n - x * 2, (m - x) / 2); // 计算 2 号礼包的个数
        ret = max(ret, a * x + b * y);
    }
    cout << ret << endl;
    return 0;
}