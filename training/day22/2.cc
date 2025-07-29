// https://www.nowcoder.com/questionTerminal/c55f4f15cc3f4ff0adede7f9c69fa0c1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int x, const vector<int>& a)
{
    int n = a.size();
    for(int i = 0; i < n; i++)
    {
        if(a[i] == x) continue;
        if(x % a[i] != 0) return false;
    }
    return true;
}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int x = a[a.size() - 1];

    if(check(x, a))  cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}