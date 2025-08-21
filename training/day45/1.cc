// https://ac.nowcoder.com/acm/problem/26229
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int res = 1;
    for(int i = 0; i < n;)
    {
        int j = i;
        while(j + 1 < n && a[j + 1] - a[j] <= 8) j++;
        
        res = max(res, j - i + 1);
        i = j + 1;
    }
    
    cout << res << endl;
    
    return 0;
}