#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n = 0; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>> a[i];

    int res = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] > a[i - 1])
        {
            res += (a[i] - a[i - 1]);
        }
    }
    cout << res << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")