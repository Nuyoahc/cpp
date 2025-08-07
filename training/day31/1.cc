// https://ac.nowcoder.com/acm/problem/229953
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n = 0, k = 0; cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++)
    {
        int x = 0; cin >> x;
        pq.push(x);
    }
    int res = 0;
    int sum = 0;
    while(sum <= k)
    {
        int t = pq.top();
        pq.pop();
        pq.push(t * 2);
        res++;
        sum += t;
    }
    cout << res - 1 << endl;
    
    return 0;    
}