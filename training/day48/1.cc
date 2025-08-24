// https://ac.nowcoder.com/acm/problem/205826
#include <iostream>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int res = 0;
    for(int i = 0; i < (n - m); i++)
    {
        int x; cin >> x;
        res += x;
    }

    double a = 0, b = 0; // 可能的最小、最大
    a = res + m * 1;
    b = res + m * 5;

    a /= n;
    b /= n;

    printf("%.5f %.5f\n", a, b);

    return 0;
}
