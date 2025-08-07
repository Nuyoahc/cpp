// https://ac.nowcoder.com/acm/problem/219035
#include<iostream>

using namespace std;

using LL = long long;

LL t, a, b, n;

LL func()
{
    LL res = 0;
    if(n <= 2) return min(a, b);
    
    if(a * 3 < b * 2) // 选双人船
    {
        res += n / 2 * a;
        n %= 2;
        if(n) res += min(min(a, b), b - a);
    }
    else // 选三人船
    {
        res += n / 3 * b;
        n %= 3;
        if(n == 1)
        {
            res += min(min(a, b), 2 * a - b);
        }
        if(n == 2)
        {
            res += min(min(a, b), 3 * a - b);
        }
    }
    return res;
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b;
        cout << func() << endl;
    }
    return 0;
}