// https://www.nowcoder.com/practice/491828fc7d93459db450b344c2aaaeef?tpId=128&tqId=33770&ru=/exam/oj
#include<iostream>
#include<vector>
#include<queue>

using namespace std;



class Solution {
    int n, m;
    int x1, y1, x2, y2;
    int dist[11][11];
    int cnt[11][11];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param CityMap int整型vector<vector<>> 
     * @param n int整型 
     * @param m int整型 
     * @return int整型
     */
    int countPath(vector<vector<int> >& CityMap, int _n, int _m) {
        // write code here
        n = _n, m = _m;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(CityMap[i][j] == 2)
                {
                    x1 = i, y1 = j; // 起点
                }
                if(CityMap[i][j] == 1)
                {
                    x2 = i, y2 = j; // 终点
                }
            }
        }

        return bfs(CityMap);
    }

    int bfs(vector<vector<int> >& CityMap)
    {
        memset(dist, -1, sizeof(dist));
        queue<pair<int, int>> q;
        q.push({x1, y1});
        dist[x1][y1] = 0;
        cnt[x1][y1] = 1;
        while(q.size())
        {
            auto [a, b] = q.front(); q.pop();
            for(int i = 0; i < 4; i++)
            {
                int x = a + dx[i];
                int y = b + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < m && CityMap[x][y] != -1)
                {
                    if(dist[x][y] == -1)
                    {
                        dist[x][y] = dist[a][b] + 1;
                        cnt[x][y] = cnt[a][b];
                        q.push({x, y});
                    }
                    else if(dist[x][y] == dist[a][b] + 1)
                    {
                        cnt[x][y] = (cnt[x][y] + cnt[a][b]);
                    }
                }
            }
        }

        return cnt[x2][y2];
    }
};