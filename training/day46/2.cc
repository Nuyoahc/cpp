#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<long long> row; // 标记⾏ y
unordered_set<long long> col; // 标记列 x
unordered_set<long long> dig1; // 标记主对⻆线 y - x
unordered_set<long long> dig2; // 标记副对⻆线 y + x

int main()
{
    int n; cin >> n;
    int res = 1e5;
    for(int i = 1; i <= n; i++)
    {
        int x, y; cin >> x >> y;
        if(res != 1e5) continue;
        if(row.count(y) || col.count(x) || dig1.count(y - x) || dig2.count(y + x))
        {
            res = i;
        }
        row.insert(y); col.insert(x); 
        dig1.insert(y - x); dig2.insert(y + x);
    }
    int t; cin >> t;
    while(t--)
    {
        int i;
        cin >> i;
        if(i >= res) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}