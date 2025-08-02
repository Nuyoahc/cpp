// https://ac.nowcoder.com/acm/problem/230720
#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
    cin >> s;
    int n = s.size();
    int res = -1;
    for(int i = 2; i < n; i++)
    {
        if(s[i] == s[i - 1] && s[i] == s[i - 2])
        {
            res = 3;
            break;
        }
    }
    for(int i = 1; i < n; i++)
    {
        if(s[i] == s[i - 1])
        {
            res = 2;
            break;
        }
    }

    
    cout << res << endl;    
    return 0;
}