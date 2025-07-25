#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using PII = pair<int, int>;

int main()
{
    int n, k; cin >> n >> k;
    vector<PII> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first;
    for(int i = 0; i < n; i++) cin >> a[i].second;

    sort(a.begin(), a.end(), [&](const PII& p1, const PII& p2){
        if(p1.second != p2.second) return p1.second > p2.second;
        return p1.first < p2.first;
    });

    long long x = 0, y = 0;
    for(int i = 0; i < k; i++)
    {
        x += a[i].first;
        y += a[i].second;
    }
    cout << x << " " << y << endl;

    
    return 0;
}