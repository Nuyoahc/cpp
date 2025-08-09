// https://www.nowcoder.com/practice/90d6a362fa7d4c519d557da797bb02ce?tpId=196&tqId=40552&ru=/exam/oj
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int hash[26] = {0};
    string s; cin >> s;

    int left = 0, right = 0;
    int res = 0;
    int kind = 0;
    while(right < s.size())
    {
        if(hash[s[right] - 'a']++ == 0) kind++;
        while (kind > 2) 
        {
            if(hash[s[left++] - 'a']-- == 1) kind--;
        }
        res = max(res, right - left + 1);
        right++;
    }
    cout << res << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")