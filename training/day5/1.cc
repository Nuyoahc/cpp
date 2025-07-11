// https://www.nowcoder.com/questionTerminal/cd117803b3364b218a8b3dcc498dee25

#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main()
{
    cin >> n;
    while(n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int score = 0;

        score = min(min(a, b), c) * 2;

        score += max(b - score / 2, 0);
        cout << score << endl;
    }

    return 0;
}