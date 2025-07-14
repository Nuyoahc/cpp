#include <iostream>
using namespace std;

// 计算最大公约数（GCD）的函数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    
    // 计算最小公倍数（LCM）
    int lcm = (a * b) / gcd(a, b);
    cout << lcm << endl;
    
    return 0;
}