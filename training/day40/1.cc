// https://ac.nowcoder.com/acm/problem/255195
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    string s; cin >> s;
    
    int res = 1e9;
    for(char ch = 'a'; ch <= 'z'; ch++)
    {
        int tmp = 0;
        for(auto &e : s)
        {
            tmp += min(abs(e - ch), 26 - abs(e - ch));
        }
        res = min(res, tmp);
    }
    cout << res << endl;
    
    return 0;
}