// https://www.nowcoder.com/practice/0045cd3e39634a66ada63c2adeb49234?tpId=230&tqId=39759&ru=/exam/oj
#include <iostream>
using namespace std;

const int N = 1010;
int a[N];
int n;
int f[N], g[N];

int main() 
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        }
    }

    for(int i = n; i >= 1; i--)
    {
        g[i] = 1;
        for(int j = i + 1; j <= n; j++)
        {
            if(a[j] < a[i]) g[i] = max(g[i], g[j] + 1);
        }
    }  

    int len = 0;
    for(int i = 1; i <= n; i++)
    {
        len = max(len, f[i] + g[i] - 1);
    }
    
    cout << n - len << endl;
    
    return 0;
}
// 64 位输出请用 printf("%lld")