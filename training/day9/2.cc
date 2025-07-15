// https://www.nowcoder.com/practice/bfb2a2b3cdbd4bd6bba0d4dca69aa3f0?tpId=230&tqId=39749&ru=/exam/oj
#include <iostream>
using namespace std;

int f[41];
int main() 
{
    int n; cin >> n;
    int res = 0;
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")