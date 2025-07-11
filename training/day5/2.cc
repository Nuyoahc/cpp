// https://www.nowcoder.com/practice/54ab9865ce7a45968b126d6968a77f34?tpId=196&tqId=40529&ru=/exam/oj
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int m, n;
    bool visited[1001][1001] = {false};
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int rotApple(vector<vector<int> >& grid) {
        // write code here
        m = grid.size();
        n = grid[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 2)
                    q.push({i, j});
        int res = -1;
        while(q.size())
        {
            int sz = q.size();
            res++;
            while(sz--)
            {
                auto [a, b] = q.front();
                q.pop();
                for(int k = 0; k < 4; k++)
                {
                    int x = a + dx[k], y = b + dy[k];
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !visited[x][y])
                    {
                        q.push({x, y});
                        visited[x][y] = true;
                    }
                }
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1 && !visited[i][j])
                    return -1;
        // 2 1 1   2 2 1   2 2 2   2 2 2   2 2 2
        // 1 0 1   2 0 1   2 0 1   2 0 2   2 0 2
        // 1 1 1   1 1 1   2 1 1   2 2 1   2 2 2
        return res;
    }

};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    int result = solution.rotApple(grid);
    cout << result << endl; // Expected output: 4

    return 0;
}