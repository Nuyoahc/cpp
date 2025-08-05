// https://ac.nowcoder.com/acm/problem/219038
// 
// 给出一个正整数H，从1开始减，第一次必须减1，每次减的数字都必须和上一次相同或者是上一次的两倍，请问最少需要几次能把H恰好减到0。
#include <iostream>
using namespace std;

int main()
{
    int n = 0; cin >> n;
    while(n--)
    {
        int h = 0; cin >> h;
        int ans = 0, step = 1;
        while (h > 0)
        {
            h -= step;
            ans++;
            if ((h % (2 * step)) == 0)
                step *= 2;
        }
        cout << ans << endl;
    }

    return 0;
}