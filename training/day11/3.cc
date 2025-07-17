#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    string s;
    getline(cin, s);
    vector<string> res;
    string tmp;
    for(int i = 0; i < s.size(); )
    {
        if(s[i] != ' ') tmp += s[i];
        if(s[i] == ' ')
        {
            res.push_back(tmp);
            tmp.clear();
        }
    }
    for(auto it = res.rbegin(); it != res.rend(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
// 64 位输出请用 printf("%lld")