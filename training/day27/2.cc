// https://www.nowcoder.com/practice/e88b41dc6e764b2893bc4221777ffe64?tpId=308&tqId=40477&ru=/exam/oj
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1010;
char grid[N][N];
int dist[N][N];

int n, m;
int x1, y1, x2, y2;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs()
{
    if(grid[x2][y2] == '*') return -1;

    memset(dist, -1, sizeof dist);
    queue<pair<int, int>> q;
    q.push({x1, y1});
    dist[x1][y1] = 0;

    while(q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && grid[nx][ny] == '.' && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                if(nx == x2 && ny == y2) return dist[x2][y2];
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() 
{   
    cin >> n >> m;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << bfs() << endl;

    return 0;
}