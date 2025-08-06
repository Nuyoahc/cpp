// https://www.nowcoder.com/practice/562630ca90ac40ce89443c91060574c6?tpId=308&tqId=40490&ru=/exam/oj
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int left = 0, right = 0;
    int res = 0;
    while(right < a.size())
    {
        while(a[right] - a[left] > k)
        {
            left++;
        }
        res = max(res, right - left + 1);
        right++;
    }
    cout << res << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")