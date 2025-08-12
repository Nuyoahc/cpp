// https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1?tpId=37&tqId=21232&ru=/exam/oj
#include <iostream>
#include <string>
using namespace std;

string str;

int main() 
{
    cin >> str;
    string res;
    
    int n = str.size();
    int hash[10] = {0};

    for(int i = n - 1; i >= 0; i--)
    {
        hash[str[i] - '0']++;
        if(hash[str[i] - '0'] == 1) res += str[i];
    }

    cout << res << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")