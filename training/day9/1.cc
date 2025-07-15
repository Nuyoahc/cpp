// https://www.nowcoder.com/practice/f51c317e745649c0900996fd3f683aed?tpId=290&tqId=39934&ru=/exam/oj

#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n; cin >> n;
    string res;
    int i = 1;
    while(n)
    {
        int t = n % 10;
        res += (t + '0');
        if(i % 3 == 0)
        {
            res += ',';
        }
        n /= 10;
        i++;
    }
    if(res.back() == ',') 
    {
        res.pop_back(); 
    }
    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")