// https://www.nowcoder.com/questionTerminal/b2b816e20e8343b49abbaf493886ce26
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    int res = n;

    for(int i = 0; i <= m - n; i++)
    {
        int tmp = 0;    
        for(int j = 0; j < n; j++)
        {
            if(s1[j] != s2[i + j]) tmp++;
        }
        res = min(res, tmp);
    }
    cout << res << endl;

    return 0;
}