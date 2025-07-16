// https://www.nowcoder.com/practice/351b87e53d0d44928f4de9b6217d36bb?tpId=230&tqId=39767&ru=/exam/oj

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<int> s;
    int res = -1;
    for(int i = 0; i < n; i++)
    {
        if(!s.empty() && s.top() < a[i])
        {
            res = max(res, a[i] - s.top());
        }
        else if(s.empty() || s.top() >= a[i])
        {
            s.push(a[i]);
        }
    }
    if (res == -1) res = 0; // If no valid pair found, return 0
    cout << res << endl;
    return 0;
}