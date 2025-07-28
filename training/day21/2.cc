// https://www.nowcoder.com/practice/635ff765d4af45b5bf8e3756ed415792?tpId=134&tqId=33860&ru=/exam/oj
#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        s.insert(x);
    }
    for(int i = 0; i < m; i++)
    {
        int x; cin >> x;
        s.insert(x);
    }
    for(auto &e : s)
    {
        cout << e << " ";
    }

    return 0;
}