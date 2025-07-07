// 求字符串中相邻的两个字符相同的字符删除掉，直到没有相同的字符为止
// 例如：abbaca -> ca
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() 
{
    string s;
    cin >> s;
    stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(st.empty() || st.top() != s[i])
        {
            st.push(s[i]);
        }
        else
        {
            st.pop();
        }
    }

    string result;
    while(!st.empty())
    {
        result = st.top() + result;
        st.pop();
    }
    if(result.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}