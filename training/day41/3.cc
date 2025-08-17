// https://ac.nowcoder.com/acm/problem/229296

#include <iostream>

using namespace std;

const int N = 2010;

int n;
int a[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    int left = 1, right = 1;
    int res = 0;
    while(left <= right)
    {
        res++;
        int r = right;
        for(int i = left; i <= right; i++)
        {
            r = max(r, a[i] + i);
            if(r >= n)
            {
                cout << res << endl;
                return 0;
            }
        }
        left = right + 1;
        right = r;
    }
    cout << -1 << endl;
    
    return 0;
}