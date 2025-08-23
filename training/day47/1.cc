// https://www.nowcoder.com/practice/351b3d03e410496ab5a407b7ca3fd841?tpId=290&tqId=39926&ru=/exam/oj
#include <iostream>
using namespace std;


int arr[15][15];
int res[15][15];
int n, m;

int main() 
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            res[j][i] = arr[i][j];
        }
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1;j <= n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")