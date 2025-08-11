// https://www.nowcoder.com/practice/196141ecd6eb401da3111748d30e9141?tpId=128&tqId=33775&ru=/exam/oj
#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int n;
    while(cin >> n)
    {
        int res = 1;
        while(res <= n)
        {
            res *= 2;
        }
        cout << res / 2 - 1 << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")