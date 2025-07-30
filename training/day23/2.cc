// https://www.nowcoder.com/questionTerminal/9fbb4d95e6164cd9ab52e859fbe8f4ec
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    set<string> ss;
    while(n--)
    {
        string s; cin >> s;
        sort(s.begin(), s.end());
    
        ss.insert(s);
    }
    cout << ss.size() << endl;

    return 0;
}