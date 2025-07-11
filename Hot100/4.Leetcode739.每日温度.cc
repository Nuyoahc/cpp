#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;
        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }   
            st.push(i);
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = solution.dailyTemperatures(temperatures);
    
    for(int i : result)
        cout << i << " ";
    cout << endl;

    return 0;
}