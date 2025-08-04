// https://www.nowcoder.com/questionTerminal/d1ac7f15d5dc40b39a7d6cb11a01407e
// 游游拿到了一个正整数，她希望你能重排这个正整数的数位，使得它变成偶数（不能有前导零）。你能帮帮她吗？
// 注：重排后可以和原数相等。
// 输入描述:
// 第一行包含一个正整数 n (1 ≤ n ≤ 100)，表示测试用
// 例的组数。
// 接下来 n 行，每行包含一个正整数 num (1 ≤ num ≤ 10
// 18)，表示游游拿到的正整数。
// 输出描述:
// 对于每个测试用例，输出一行，表示重排后的数位
// 是否能变成偶数。如果能，输出重排后的数位；如果不能，输出 -1。
// 示例1
// 输入
// 2
// 123
// 1234
// 输出
// 132
// 1234

#include <iostream>
#include <string>
using namespace std;

string solve(string& num)
{
    bool flag = false; // 默认没有任何一位数字是偶数
    int tmp = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if ((num[i] - '0') % 2 == 0)
        {
            flag = true;
            tmp = i;
            break;
        }
    }
    if (flag)
    {
        if (num[num.size() - 1] != '0')
            swap(num[tmp], num[num.size() - 1]);
        
        return num;
    }
    else
    {
        return "-1";
    }

}

int main()
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")