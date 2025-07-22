// https://ac.nowcoder.com/acm/problem/205350

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x;
    cin >> x;
    x = sqrt(x);

    int y1 = x * x;
    int y2 = (x + 1) * (x + 1);

    int res = 0;
    res = (x - y1) > (y2 - x) ? y2 : y1;

    cout << res << endl;

    return 0;
}