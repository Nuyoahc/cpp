// https://ac.nowcoder.com/acm/problem/205832
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    int hash[26] = {0};
    char res;
    int maxCount = -1;
    
    while(cin >> s)
    {
        for(auto &e : s)
        {
            hash[e - 'a']++;
            
            if(hash[e - 'a'] > maxCount)
            {
                res = e;
                maxCount = hash[e - 'a'];
            }
        }
    }

    cout << res << endl;
    
    return 0;
}