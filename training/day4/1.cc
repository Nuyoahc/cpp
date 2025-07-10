// https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=122&tqId=33668&ru=/exam/oj
// 
#include <iostream>
using namespace std;
const int N = 1000001;

int main()
{
    int n;
    cin >> n;
    int a[N];
    int a_min, a_max;
    a[1] = 1;
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
        if (a[i] < n)
            a_min = a[i];
        else
        {
            a_max = a[i];
            break;
        }
    }
    cout << min((a[n] - a_min), (a_max - a[n])) << endl;

    return 0;
}