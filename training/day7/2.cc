#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */
    bool visited[1000][1000];
    int dx[4] = {-1, 1, 0, 0}; // 上下左右
    int dy[4] = {0, 0, -1, 1};
    int solve(vector<vector<char>> &grid)
    {
        // write code here

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    count++;
                    dfs(grid, i, j);
                }
            } 
        }
        return count;
    }

    void dfs(vector<vector<char>> &grid, int i, int j)
    {

        visited[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
                grid[x][y] == '1' && !visited[x][y])
            {
                dfs(grid, x, y);
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '1', '1'},
        {'0', '0', '0', '1', '0'},
        {'0', '1', '1', '0', '0'},
        {'1', '0', '0', '0', '1'}};

    int result = solution.solve(grid);
    cout << result << endl; // 输出岛屿数量
    return 0;
}