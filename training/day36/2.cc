// https://www.nowcoder.com/practice/4c0419eb07c840ca8402e4f2a52cfd49?tpId=308&tqId=40489&ru=/exam/oj
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using LL = long long;
int main() 
{
    int n; cin >> n;
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    for(int i = 0; i < n; i++)
    {
        LL x; cin >> x;
        pq.push(x);
    }

    LL res = 0;
    while(pq.size() > 1)
    {
        LL a = pq.top(); pq.pop();
        LL b = pq.top(); pq.pop();
        res += (a + b);
        pq.push(a + b);
    }

    cout << res << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")