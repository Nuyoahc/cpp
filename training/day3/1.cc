// https://www.nowcoder.com/practice/0cfa856bf0d649b88f6260d878f35bb4?tpId=290&tqId=39937&ru=/exam/oj
// 题目描述
// 给定一个字符串，要求将字符串中每个单词的首字母转换
// 为大写字母，其他字母不变。单词之间用空格隔开，字符串的首字母一定是小写字母。
// 输入描述:
// 输入一行字符串，长度不超过1000。
// 输出描述:
// 输出转换后的字符串。

// 笨蛋模拟
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     string s;
//     getline(cin, s);
//     string res;
//     if('a' <= s[0] && s[0] <= 'z')
//         res = (s[0] - 32);
//     else
//         res = s[0];
//     for(int i = 1; i < s.size(); i++)
//     {
//         if(s[i] == ' ')
//         {
//             if('a' <= s[i + 1] && s[i + 1] <= 'z')
//             {
//                 s[i + 1] = s[i + 1] - 32;
//                 res += s[i + 1];
//             }
//             else
//             {
//                 res += s[i + 1];
//             }
//         }
//     }

//     cout << res << endl;
//     return 0;
// }
// // 64 位输出请用 printf("%lld")


// 高手使用    while (cin >> s) // ⾃动跳过空格
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    while (cin >> s) // ⾃动跳过空格
    {
        if (s[0] <= 'z' && s[0] >= 'a')
            cout << (char)(s[0] - 32);
        else
            cout << s[0];
    }
    return 0;
}