// 链接：https://ac.nowcoder.com/acm/problem/230830
// 来源：牛客网

// 给定一个长度为偶数的环形 01 字符串。（环形指，第一个字符和最后一个字符是相邻的）
// 字符串初始每个字符都是白色。小葱想把一段连续区间染成红色，使得红色的字符'0'数量等于白色的字符'0'数量，红色的字符'1'数量等于白色的字符'1'数量。问有多少种不同的染色方法？
// 两个方案不同当且仅当存在一个某字符，在一个方案是染成红色，在另一个方案为白色。

// 输入描述：
// 第一行包含一个整数 n (2 ≤ n ≤ 10^5)，表示字符串的长度。
// 第二行包含一个长度为 n 的字符串 s，字符串只包含字符 '0' 和 '1'。
// 输出描述：
// 输出一个整数，表示满足条件的染色方法数。

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    int hash[2] = {0};
    for(auto &e : s)
    {
        hash[e - '0']++; // 统计0 1的个数
    }
    
    int left = 0, right = 0, half = n / 2;
    int res = 0;
    int count[2] = {0};
    while(right < n - 1) // 判断第一个区间时，也已经判断了最后一个区间
    {
        count[s[right] - '0']++;
        while(right - left + 1 > half)
        {
            count[s[left] - '0']--;
            left++;
        }
        if(right - left + 1 == half)
        {
            if(count[0] * 2 == hash[0] && count[1] * 2 == hash[1]) // 何时合法？
            {
                res += 2;
            } 
        }
        right++;
    }
    
    cout << res << endl;
    return 0;
}