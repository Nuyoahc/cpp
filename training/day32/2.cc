// https://www.nowcoder.com/practice/16d971e9e42e4f3b9b1e2b8794796a43?tpId=308&tqId=40488&ru=/exam/oj
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using PII = pair<int, int>;

int main()
{
    int n = 0; cin >> n;
    vector<PII> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](const PII &x, const PII &y) {
        return x.second < y.second;
    });

    int res = 0;
    int end = a[0].second;
    for (int i = 1; i < n; i++)
    {
        if(a[i].first >= end)
        {
            res ++;
            end = a[i].second;
        }
        else
        {
            end = min(end, a[i].second);
        }
    }
    cout << res << endl;

    return 0;
}