#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 栈排序
     * @param a int整型vector 描述入栈顺序
     * @return int整型vector
     */
    vector<int> solve(vector<int>& a) {
        // write code here
        int n = a.size();
        stack<int> st;
        vector<int> res;
        int hash[50010] = {0};
        int aim = n;

        for(int i = 0; i < n; i++)
        {
            int x = a[i];
            st.push(x);
            hash[x] = 1;

            while(hash[aim])
            {
                aim--;
            }

            while(st.size() && st.top() >= aim)
            {
                res.push_back(st.top()); st.pop();
            }
        }
        
        return res;
    }
};