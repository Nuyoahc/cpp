// 大数相乘
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string mul(string str1, string str2) 
{
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int n = str1.size(), m = str2.size();
    vector<int> tmp(n + m, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            tmp[i + j] += (str1[i] - '0') * (str2[j] - '0');
            tmp[i + j + 1] += tmp[i + j] / 10;
            tmp[i + j] %= 10;
        }
    }
    while (tmp.size() > 1 && tmp.back() == 0) tmp.pop_back();
    reverse(tmp.begin(), tmp.end());
    string result;
    for (int digit : tmp) result.push_back(digit + '0');
    return result;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    cout << mul(str1, str2) << endl;
    return 0;
}