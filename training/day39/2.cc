// https://www.nowcoder.com/practice/c471efdbd33a4a979539a91170c9f1cb?tpId=128&tqId=33774&ru=/exam/oj.
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() 
{
    string s;
    while (cin >> s) 
    { 
        int hash[300] = {0};
        for(auto &e : s)
        {
            hash[e]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &e : hash)
        {
            if(e) pq.push(e);
        }

        int res = 0;
        while(pq.size() > 1)
        {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            res += (a + b);
            pq.push(a + b);
        }

        cout << res << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")