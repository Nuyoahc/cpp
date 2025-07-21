// https://www.nowcoder.com/questionTerminal/bb4f1a23dbb84fd7b77be1fbe9eaaf32

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    while(cin >> str1 >> str2){
        int hash[26] = { 0 };
        for(auto &e : str1) hash[e - 'A']++;

        string ans = "Yes";
        for(auto &e : str2) 
        {
            if(--hash[e - 'A'] < 0)
            {
                ans = "No";
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}