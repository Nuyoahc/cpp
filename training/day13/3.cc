#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

int n;
string s;

int main()
{
    cin >> n >> s;
    int hash[26] = { 0 };
    int maxCount = 0;
    char maxChar = 0;
    // 统计所有字符的个数 && 出现次数最多的字符及其个数
    for(auto &e : s)
    {
        if(++ hash[e - 'a'] > maxCount)
        {
            maxChar = e;
            maxCount = hash[e - 'a'];
        }
    }
    // 判断是否可以重排
    if((n + 1) / 2 < maxCount) cout << "no" << endl;
    else
    {
        cout << "yes" << endl;
        // 先排出现次数最多的字符
        string ans;
        ans.resize(n, ' ');
        int i = 0;
        while(maxCount --)
        {
            ans[i] = maxChar;
            i += 2;
        }
        
        for(int j = 0;j < 26;j ++)
        {
            if(hash[j] && j + 'a' != maxChar)
            {
                while(hash[j] --)
                {
                    if(i >= n) i = 1;
                    ans[i] = j + 'a';
                    i += 2;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
