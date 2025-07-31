// https://www.nowcoder.com/practice/a5a0b05f0505406ca837a3a76a5419b3?tpId=230&tqId=40416&ru=/exam/oj

#include <iostream>

using namespace std;

const int N = 110;
int a[N][N] = {0};
int sum[N][N] = {0};
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int res = -N;
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= n; y2++) 
                {
                    res = max(res, sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]);
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}