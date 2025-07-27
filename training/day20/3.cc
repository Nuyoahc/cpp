// https://ac.nowcoder.com/acm/problem/214851

#include <iostream>
#include <string>

using namespace std;

bool check(string s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}
bool isSame(string s)
{ // 判断是否只有一种字母
    auto cur = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (cur != s[i])
            return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (isSame(s))
    { // 如果是"aaaaaaa"的情况,输出0
        cout << 0 << endl;
        return 0;
    }
    if (!check(s))
    {
        cout << s.size() << endl;
    }
    else
    {
        cout << s.size() - 1 << endl;
    }

    return 0;
}