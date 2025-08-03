// https://ac.nowcoder.com/acm/problem/500399
#include <iostream>
using namespace std;

const int mod = 109;
int n, m, res;

int main()
{
    cin >> n >> m;
    res = n;
    for (int i = 1; i < m; i++)
    {
        res = res * (n - 1) % mod;
    }
    cout << res << endl;
    
    return 0;
}