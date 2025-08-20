// https://ac.nowcoder.com/acm/problem/50042
#include <iostream>
using namespace std;

const int N = 11;
const int M = 1010;

int n, arr[N];
bool visited[M];
int path;
int res = 0x3f3f3f3f;

bool is_prime(int x)
{
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

void dfs(int pos)
{
    if(pos == n)
    {
        res = min(res, arr[pos - 1]);
    }

    for(int i = pos; i < n; i++)
    {
        if(!visited[arr[i]] && is_prime(i) && arr[pos] % i == 0)
        {
            visited[arr[i]] = true;
            path += i;
            dfs(pos + 1);
            path -= i;
            visited[arr[i]] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dfs(0);

    if(res == 0x3f3f3f3f)
    {
        cout << "-1" << endl;
    }

    return 0;
}