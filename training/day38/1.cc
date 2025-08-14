// https://ac.nowcoder.com/acm/problem/219641#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> f(n + 1); // 前 i 个的最大值；
    vector<int> g(n + 1); // 前 i 个的最小值；
    f[1] = a[1];
    for(int i = 2; i <= n ;i++)
    {
        f[i] = max(f[i - 1], a[i]);
        if(a[i] > f[i - 1]) // 大于前一个位置的最大值
        {
            g[i] = f[i - 1];           
        }
        else if(a[i] > g[i - 1]) // 大于前一个位置的次大值
        {
            g[i] = a[i];
        }
        else
        {
            g[i] = g[i - 1];
        }
    }
    
    int q; cin >> q;
    while(q--)
    {
        int x; cin >> x;
        cout << g[x] << endl;
    }
    
    return 0;
}