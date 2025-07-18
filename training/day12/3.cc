#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    string str;
    cin >> n >> str;
    int s[300000], h[300000], y[300000];
    s[0] = str[0] == 's' ? 1 : 0;
    for(int i = 0; i < n; i++)
    {
        char ch = str[i];
        if(ch == 's') s[i] = s[i - 1] + 1;
        else s[i] = s[i - 1];
        if(ch == 'h') h[i] = s[i - 1] + h[i - 1];
        else h[i] = h[i - 1];
        if(ch == 'y') y[i] = h[i - 1] + y[i - 1];
        else y[i] = y[i - 1];
    }
    cout << y[n - 1] << endl;

    return 0;
}