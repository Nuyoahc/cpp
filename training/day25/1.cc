// https://www.nowcoder.com/practice/17865bc2a75c4944a872ef709958c56e?tpId=290&tqId=39933&ru=/exam/oj
#include <iostream>
#include <string>
using namespace std;

bool func(int x)
{
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0) return false;
    }

    return true;
}

int main()
{
    string s; cin >> s;
    int maxn = 0, minn = 0;
    int hash[26] = {0};
    for(auto e : s)
    {
        hash[e - '0']++;
        if(hash[e - '0'] > maxn) maxn = hash[e - '0'];
        else minn = hash[e - '0'];
    }

    if(func(maxn - minn))
    {
        cout << "Lucky Word" << endl;
        cout << (maxn - minn) << endl;
    }
    else
    {
        cout << "No Answer" << endl;
        cout << "0" << endl;
    }

    return 0;
}