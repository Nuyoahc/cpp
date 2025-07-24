// https://www.nowcoder.com/practice/fcd30aac9c4f4028b23919a0c649824d?tpId=290&tqId=39833&ru=/exam/oj

#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if((s[i] - '0') % 2 == 0)
        {
            s[i] = '0';
        }
        else
        {
            s[i] = '1';
        }
    }

    // 除去前导0
    while(s.size() > 1 && s[0] == '0')
    {
        s.erase(s.begin());
    }
    cout << s << endl;

    return 0;
}