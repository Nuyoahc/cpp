// https://www.nowcoder.com/practice/d638855898fb4d22bc0ae9314fed956f?tpId=290&tqId=39945&ru=/exam/oj
#include <iostream>
#include <string>

using namespace std;
using LL = long long;

LL x;

bool is_prime(LL x)
{
    if(x <= 2) return false;
    for(LL i = 3; i * i <= x; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

bool check()
{
    string s = to_string(x);
    string tmp;
    for(int i = s.size() - 2; i >= 0; i--)
    {
        tmp += s[i];
    }
    s += tmp;
    LL num = stoll(s);
    if(is_prime(num)) return true;
    return false;
}

int main()
{
    cin >> x;
    if(check())
    {
        cout << "prime" << endl;
    }
    else
    {
        cout << "noprime" << endl;
    }

    return 0;
}