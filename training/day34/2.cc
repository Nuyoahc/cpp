// https://ac.nowcoder.com/acm/problem/50041
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using PII = pair<int, int>;

const int N = 40;
char a[N][N];
int dist[N][N];
queue<PII> q;
int n, m;
int x, y;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs()
{
    memset(dist, -1, sizeof dist);
    dist[x][y] = 0;
    q.push({x, y});
 
    while(q.size())
    {
        auto [x1, y1] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++)
        {
            int nx = x1 + dx[k];
            int ny = y1 + dy[k];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1 && a[nx][ny] != '*')
            {
                dist[nx][ny] = dist[x1][y1] + 1;
                if(a[nx][ny] != 'e')
                {
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'k'){
                x = i, y = j;
            }
        }
    bfs();
    int res = 0, min_dist = 1e9;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(dist[i][j] != -1 && a[i][j] == 'e')
            {
                res++;
                min_dist = min(min_dist, dist[i][j]);
            }
        }
    
    if(res == 0) cout << "-1" << endl;
    else cout << res << " " << min_dist << endl;
    
    return 0;
}