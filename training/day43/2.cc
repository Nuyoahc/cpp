// https://ac.nowcoder.com/acm/problem/26224
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200010;

int n, l, r;
int a[N];

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    long long res = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        int left_bound = a[i] + l;
        int right_bound = a[i] + r;
        // 找到第一个大于等于left_bound的位置
        int j = lower_bound(a + i + 1, a + n, left_bound) - a;
        // 找到第一个大于right_bound的位置
        int k = upper_bound(a + i + 1, a + n, right_bound) - a;
        res += (k - j);
    }
    
    cout << res << endl;
    
    return 0;
}