// https://ac.nowcoder.com/acm/problem/202487
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, a, H, A;
        cin >> h >> a >> H >> A;
        int ans = 0;

        int bleed = H;
        if (a >= H)
            cout << "-1" << endl;
        else
        {
            while (h > 0)
            {
                H -= a;
                if (H <= 0)
                {
                    ans++;
                    H = bleed;
                }
                else
                {
                    h -= A;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}