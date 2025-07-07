// 输出n,m中所有数字2的个数
// 例如：n=1,m=20，输出12
#include <iostream>
using namespace std;

int two(int n)
{
    int res = 0;
    while(n > 0)
    {
        int digit = n % 10;
        if(digit == 2)
        {
            res++;
        }
        n /= 10;
    }
    return res;
}

int func(int n, int m)
{
    int res = 0;
    for(int i = n; i <= m; i++)
    {
        res += two(i);
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int result = 0;
    result = func(n, m);
    cout << result << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
