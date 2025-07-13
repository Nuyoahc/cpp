// https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=182&tqId=34785&ru=/exam/oj

#include <iostream>
#include <string>

using namespace std;

// abcd12345ed125ss123456789
// 123456789
int main()
{
    string str;
    cin >> str;
    string res, tmp;
    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] <= '9' && str[i] >= '0')
        {
            tmp += str[i];
        }
        else
        {
            if(res.size() < tmp.size())
            {
                res = tmp;
            }
            else
            {
                tmp.clear();
            }
        }
    }
    cout << res << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")