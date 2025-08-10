// https://www.nowcoder.com/practice/7a71a88cdf294ce6bdf54c899be967a2?tpId=196&tqId=37184&ru=/exam/oj

class Solution {
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    int m, n;
    vector<vector<int>> memo; // 改用动态数组

public:
    int solve(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        m = matrix.size(), n = matrix[0].size();
        memo.resize(m, vector<int>(n, -1)); // 初始化为 -1

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, i, j));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (memo[i][j] != -1) return memo[i][j]; // 已计算过

        int res = 1; // 至少包含自己
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                res = max(res, dfs(matrix, x, y) + 1);
            }
        }
        memo[i][j] = res; // 记忆化
        return res;
    }
};