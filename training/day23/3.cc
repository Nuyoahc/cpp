// https://www.nowcoder.com/practice/71cde4dee669475f94d8d38832374ada?tpId=196&tqId=40411&ru=/exam/oj
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param m int整型vector<vector<>>
     * @return int整型
     */
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool visited[201][201];
    int a, b;
    int res;
    int citys(vector<vector<int>> &m)
    {
        // write code here
        a = m.size();
        b = m[0].size();
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                if(m[i][j] == 1 && !visited[i][j])
                {
                    res++;
                    dfs(m, i, j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &m, int x, int y)
    {
        visited[x][y] = true;
        for(int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >= 0 && newX < a && newY >= 0 && newY < b && m[newX][newY] == 1 && !visited[newX][newY])
            {
                dfs(m, newX, newY);
            }
        }
    }
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param m int整型vector<vector<>> 
     * @return int整型
     */
    bool visited[201] = {0};
    int citys(vector<vector<int> >& m) {
        // write code here
        int n = m.size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                res++;
                dfs(m, i);
            }
        }
        return res;
    }
    void dfs(vector<vector<int> >& m, int x)
    {
        visited[x] = true;
        for(int i = 0; i < m.size(); i++)
        {
            if(!visited[i] && m[x][i]) dfs(m, i);
        }
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> m = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << sol.citys(m) << endl;
    return 0;
}
