// https://ac.nowcoder.com/acm/problem/202493
#include <iostream>
#include <vector>

using namespace std;

int arr[6];
bool same[13][13]; // i, j 的答案相同
int res;
vector<int> path; // 记录路径⾥⾯选了哪些选项

bool isSame(int pos, int cur)// pos 位置填 cur ，是否符合要求
{
    for(int i = 1; i < pos; i++)
    {
        if(same[pos][i] && path[i] != cur) return false;
    }
    return true;
    
}

void dfs(int pos)
{
    if(pos > 12)
    {
        res++;
        return ;
    }
    
    for(int i = 1; i <= 4; i++)
    {
        if(arr[i] == 0) continue; // 选项已经用完了
        
        if(!isSame(pos, i)) continue; 
        
        arr[i]--;
        path.push_back(i);
        dfs(pos + 1);
        path.pop_back();
        arr[i]++;
    }
    
}

int main()
{
    for(int i = 1; i <= 5; i++) cin >> arr[i];
    
    int t = arr[5];
    while(t--)
    {
        int x, y;
        cin >> x >> y;
        same[x][y] = same[y][x] = true;
    }
    
    path.push_back(0); // 填 0 位置（类似于占位符）
    dfs(1);
    
    cout << res <<endl;
    
    
    return 0;
}