// https://www.nowcoder.com/questionTerminal/af6d52eb400b40fd9652b089216f113e
#include <iostream>
using namespace std;

bool visited[11] = {0};
int sum = 0; // 路径和
int n, m; 

void dfs(int pos)
{
    if(sum == m)
    {
        for(int i = 1; i <= n; i++)
        {
            if(visited[i]) cout << i << " "; 
        }
        cout << endl;
        return ;
    }
    if(sum > m || pos > n) return ;

    // 选 pos
    sum += pos;
    visited[pos] = true;
    dfs(pos + 1);
    sum -= pos;
    visited[pos] = false;

    // 不选 pos
    dfs(pos + 1);

}
int main() 
{
    cin >> n >> m;
    dfs(1);

    return 0;
}
// 64 位输出请用 printf("%lld")