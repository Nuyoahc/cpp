// https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=122&tqId=33649&ru=/exam/oj

#include <iostream>
using namespace std;

int n, a;

int gcd1(int a, int b)
{
    return a % b == 0 ? b : gcd1(b, a % b);
}

int gcd2(int a, int b)
{
    while(a != b)
    {
        if(a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

int main() 
{
    while(cin >> n >> a)
    {
        for(int i = 0; i < n; i++)
        {
            int x; cin >> x;
            if(a >= x) a += x;
            else a += gcd1(a, x);
        }
        cout << a << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")