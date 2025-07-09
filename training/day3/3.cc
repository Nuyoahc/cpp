// https://ac.nowcoder.com/acm/problem/213140

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    priority_queue<int> pq; // 大堆
    for (int i = 0; i < n; i++)
        pq.push(a[i]);
    long long res = 0;
    for (int i = 0; i < k;)
    {
        if (pq.empty())
            break;
        if (pq.top() % 2 != 0)
        {
            int t = pq.top();   
            res += t;       
            pq.pop();
        }
        else
        {
            int t = pq.top();      
            pq.push(t / 2);
            pq.pop();
            i++;
        }
    }
    // 11 + 5 + 4
    while(pq.size() > 0)
    {
        res += pq.top();
        pq.pop();
    }
    cout << res << endl;

    return 0;
}
