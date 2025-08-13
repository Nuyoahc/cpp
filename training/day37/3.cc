// https://www.nowcoder.com/practice/36d613e0d7c84a9ba3af3ab0047a35e0?tpId=230&tqId=39760&ru=/exam/oj
#include <iostream>
using namespace std;
const int N = 110;
int n, m;
int arr[N][N];
int dp[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dfs(int i, int j)
{
    if (dp[i][j])
        return dp[i][j];
    int len = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= m && arr[x][y] < arr[i][j])
        {
            len = max(len, 1 + dfs(x, y));
        }
    }
    dp[i][j] = len;
    return len;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ret = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ret = max(ret, dfs(i, j));
        }
    }
    cout << ret << endl;
    return 0;
}