// https://www.nowcoder.com/practice/95712f695f27434b9703394c98b78ee5?tpId=290&tqId=39864&ru=/exam/oj
#include <iostream>
#include <string>
using namespace std;

string str;

int main() 
{
    cin >> str;
    int n = str.size();

    int a1 = str[0] - '0';
    int a2 = str[2] - '0';
    int a3 = str[3] - '0';
    int a4 = str[4] - '0';
    int a5 = str[6] - '0';
    int a6 = str[7] - '0';
    int a7 = str[8] - '0';
    int a8 = str[9] - '0';
    int a9 = str[10] - '0';

    int x = str[str.size() - 1] - '0';
    int y = (a1*1 + a2*2 + a3*3 + a4*4 + a5*5 + a6*6 + a7*7 + a8*8 + a9*9) % 11;

    if(y == 10)
    {
        if(str[str.size() - 1] == 'X') cout << "Right" << endl;
        else
        {
            str[str.size() - 1] = 'X';
            cout << str << endl;
        }
    }
    else 
    {
        if(x == y) cout << "Right" << endl;
        else
        {
            str[str.size() - 1] = y + '0';
            cout << str << endl;
        }
    }


    return 0;
}
// 64 位输出请用 printf("%lld")