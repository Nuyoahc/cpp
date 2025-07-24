// https://ac.nowcoder.com/acm/problem/205836

#include <iostream>
#include <vector>
using namespace std;

using LL = long long;
int main()
{ 
    LL n, m;
    cin >> n >> m;
    vector<vector<LL>> a(n, vector<LL>(m));
    vector<vector<LL>> res(n, vector<LL>(m));
    vector<LL> rowSum(n, 0); // 行和
    vector<LL> colSum(m, 0); // 列和
    
    for (LL i = 0; i < n; ++i)
    {
        for (LL j = 0; j < m; ++j)
        {
            // cin >> a[i][j];
            scanf("%ld", &a[i][j]);
            rowSum[i] += a[i][j];
            colSum[j] += a[i][j];
        }
    }

    for (LL i = 0; i < n; ++i)
    {
        for (LL j = 0; j < m; ++j)
        {
            // cout << rowSum[i] + colSum[j] - a[i][j] << " ";
            printf("%ld ", rowSum[i] + colSum[j] - a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

