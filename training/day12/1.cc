#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, deleteStr;
    getline(cin, s);
    getline(cin, deleteStr);
    string res;

    for(int i = 0; i < s.size(); i++)
    {
        if(deleteStr.find(s[i]) == string::npos)
        {
            res += s[i];
        }
    }

    cout << res << endl;

    return 0;
}