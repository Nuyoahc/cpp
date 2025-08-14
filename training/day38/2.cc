// https://ac.nowcoder.com/acm/problem/221786
#include <iostream>
#include <vector>

using namespace std;

void Row(vector<vector<int>>& a) // 行
{
    int n = a.size();
    for(int i = 0; i < n / 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            swap(a[i][j], a[n - 1 - i][j]);
        }
    }
}

void Col(vector<vector<int>>& a) // 列
{
    int n = a.size();
    for(int j = 0; j < n / 2; j++)
    {
        for(int i = 0; i < n; i++)
        {
            swap(a[i][j], a[i][n - 1 - j]);
        }
    }
}

int main()
{
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    int q, x;
    cin >> q;
    
    int row = 0, col = 0;
    while(q--)
    {
        int x = 0;
        cin >> x;
        if(x == 1) row++, col++;
        else row++;
    }
    
    row %= 2, col %= 2;
    
    if(row) Row(a);
    if(col) Col(a);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}