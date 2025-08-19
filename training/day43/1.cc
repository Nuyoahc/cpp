// https://ac.nowcoder.com/acm/problem/50044
#include<iostream>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    double res = 1.0;
    for(int i = n; i >= n - m + 1; i--) res *= i;
    for(int i = m; i >= 1; i--) res /= i;
    for(int i = 0; i < m; i++) res *= 0.8;
    for(int i = 0; i < n - m; i ++) res *= 0.2;
    
    printf("%.4f\n", res);
    
    return 0;
}