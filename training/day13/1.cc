#include <iostream>

using namespace std;

int main()
{
    int t = 0; cin >> t;
    while(t--)
    {
        int n, k, res; 
        string s;
        cin >> n >> k;
        cin >> s;
        res = (s[0] == 'W' ? 1 : -1);
        res += (s[1] == 'W' ? 1 : -1);
        for(int i = 2; i < s.size(); i++)
        {
            if(s[i] == 'L') res--;
            else 
            {
                if(s[i - 1] == 'W' && s[i - 2] == 'W') res += k;
                else res ++;
            }
        }
        cout << res << endl;
    }
    
    return 0;
}