// https://ac.nowcoder.com/acm/problem/229386
// dd作为体操队队长，在给队员们排队形，体操队形为一个单独的纵列，体操队有n个队员，标号为1~n，
// 对于i(1 <= i <= n)号队员，dd希望他站在第a[i]个位置前，当a[i] = i时，表示该队员站在任何位置前。
// 有多少种队形满足dd的要求？
// 输入描述：
// 第一行一个整数n(1 <= n <= 10)，表示队员的数量。
// 第二行n个整数a[i](1 <= a[i] <= n)，表示每个队员希望站在的位置前。
// 输出描述：
// 输出一个整数，表示满足dd要求的队形数量。


#include <iostream>

using namespace std;

int n, a[11], ans;
int vis[11];

void dfs(int pos)
{
    if(pos > n)
    {
        ans++;
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(vis[i]) continue; // 如果i号队员已经被使用，跳过
        if(vis[a[i]]) return; // 如果a[i]号队员已经被使用，跳过
        vis[i] = 1; // 标记i号队员已使用
        dfs(pos + 1); // 递归处理下一个位置
        vis[i] = 0; // 回溯，取消标记i号队员未使用
    }

}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    dfs(1);

    cout << ans << endl;

    return 0;
}