// https://www.nowcoder.com/practice/cdf0808f841748faba058c8ef538c731?tpId=308&tqId=40484&ru=/exam/oj
#include <iostream>
using namespace std;

const int MOD = 1000000007;

int n;

int main() 
{
    cin >> n;
    int x = 1, y = 2;
    for(int i = 2; i <= n; i++)
    {
        int xx = 2 * y % MOD + 1;
        int yy = (2 * y % MOD + 2 + x) % MOD;
        x = xx;
        y = yy;
    }
    cout << x << " " << y << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")