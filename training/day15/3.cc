#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 2e5 + 10;
vector<vector<int>> edges(N); // edges[i] 表⽰ i 这个点所连接的边的信息
int in[N];                    // 统计⼊度信息
int n, m;
queue<int> q;
vector<int> ret; // 记录最终结果

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b); // 存储边的信息
        in[b]++;               // 存储⼊度
    }
    for (int i = 1; i <= n; i++) // 把⼊度为 0 的点放进队列中
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int a = q.front();
        q.pop();
        ret.push_back(a);
        for (auto b : edges[a])
        {
            if (--in[b] == 0)
            {
                q.push(b);
            }
        }
    }
    // 判断
    if (ret.size() == n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << ret[i] << " ";
        }
        cout << ret[n - 1];
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}