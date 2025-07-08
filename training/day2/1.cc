// 计算价格
// Leetcode 102. 计算价格
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a;
    char b;
    cin >> a >> b;
    int cost = 20;
    if (a > 1) {
        // 向上取整计算超出 1kg 部分的重量
        int extra = ceil(a - 1);
        cost += extra * 1;
    }
    if (b == 'y') {
        cost += 5;
    }
    cout << cost << endl;
    return 0;
}