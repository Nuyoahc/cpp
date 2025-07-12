// https://www.nowcoder.com/practice/11ae12e8c6fe48f883cad618c2e81475?tpId=196&tqId=37176&ru=/exam/oj
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        string res;
        int i = s.size() - 1, j = t.size() - 1;
        int tmp = 0;
        while(i >= 0 || j >= 0 || tmp)
        {
            if(i >= 0) tmp += s[i--] - '0';
            if(j >= 0) tmp += t[j--] - '0';
            res += '0' + tmp % 10;
            tmp /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() 
{
    Solution sol;
    string s, t;
    cin >> s >> t;
    cout << sol.solve(s, t) << endl;
    return 0;
}