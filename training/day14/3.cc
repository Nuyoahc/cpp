#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int sum[N]; // sum[i] 表⽰ i 出现的总和
int n;
int f[N], g[N];
int main()
{
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum[x] += x;
    }
    for (int i = 1; i < N; i++)
    {
        f[i] = g[i - 1] + sum[i];
        g[i] = max(f[i - 1], g[i - 1]);
    }
    cout << max(f[N - 1], g[N - 1]) << endl;
    
    return 0;
}