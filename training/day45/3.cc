// https://www.nowcoder.com/practice/ba3c096c19e04afbbbd59250e909ac68?tpId=230&tqId=39770&ru=/exam/oj
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1010, M = 110;
int n, k, p[N];
int f[N][M], g[N][M];

int main() 
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> p[i];


    memset(f, -0x3f3f3f3f, sizeof f);
    memset(g, -0x3f3f3f3f, sizeof g);
    k = min(k, n / 2);
    f[0][0] = -p[0];
    g[0][0] = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            f[i][j] = max(f[i - 1][j], g[i - 1][j] - p[i]);
            g[i][j] = g[i - 1][j];
            if(j >= 1) g[i][j] = max(g[i][j], f[i - 1][j - 1] + p[i]);
        }
    }

    int ret = 0;
    for(int j = 0; j <= k; j++) ret = max(ret, g[n - 1][j]);

    cout << ret << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")