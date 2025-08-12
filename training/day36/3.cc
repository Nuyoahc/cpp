// https://www.nowcoder.com/practice/0a8bbf8b9b5b4280957849ef4f240f07?tpId=230&tqId=38957&ru=/exam/oj
#include <iostream>
#include <string>
using namespace std;

const int N = 1e5 + 10;

int f[26];  // f[x]表示以字符x结尾的"ab"形式子序列数量
int g[26];  // g[x]表示字符x出现的总次数
int dp[N];  // dp[i]表示以i为结尾的"abb"形式子序列数量

int main() 
{
    int n = 0; cin >> n;
    string s; cin >> s;

    long long res = 0;  // 存储最终结果，使用long long避免溢出
    for(int i = 0; i < n; i++)
    {
        int x = s[i] - 'a';  // 将字符转换为0-25的索引
        
        // 累加当前字符作为最后一个b时能形成的abb子序列数量
        res += f[x];
        
        // 更新以当前字符为结尾的ab子序列数量
        f[x] = f[x] + i - g[x];
        
        // 更新当前字符的出现次数
        g[x] = g[x] + 1;
    }
    
    cout << res << endl;
    return 0;
}