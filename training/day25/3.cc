// https://www.nowcoder.com/practice/65ade309fa4d4067a9add749721bfdc0?tpId=230&tqId=40433&ru=/exam/oj

#include <iostream>
using namespace std;

const int N = 501;
const int M = 501 * 101;
int dp[N][M];
int a[N];

int main() {
    int n = 0;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n ; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 1) cout << "false" << endl;
    else {
        sum /= 2;
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= a[i]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - a[i]];
                }
            }
        }
        if (dp[n][sum]) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")