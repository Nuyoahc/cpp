// https://ac.nowcoder.com/acm/problem/221681]  
// 题目描述
// 给定一个整数数组和一个整数 x，找到和大于等于 x 的最短子数组的起始和结束位置。如果不存在这样的子数组，输出 -1 -1。
// 输入描述
// 第一行包含两个整数 n 和 x，分别表示数组的长度和目标和。
// 第二行包含 n 个整数，表示数组的元素。
// 输出描述
// 输出两个整数，表示最短子数组的起始和结束位置（从1开始计数）。如果不存在这样的子数组，输出 -1 -1。

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int resL = -1, resR = -1;
    int left = 0, right = 0, sum = 0;
    int len = n + 1; // 初始化为 n + 1，比任何可能子数组长度都大
    while(right < n)
    {
        sum += a[right];
        while(sum >= x)
        {
            if(right - left + 1 < len)
            {
                resL = left;
                resR = right;
                len = right - left + 1;
            }
            sum -= a[left++];
        }
        right++;
    }
    if (resL == -1) {
        cout << "-1 -1" << endl; // 明确处理无解情况
    } else {
        cout << resL + 1 << " " << resR + 1 << endl;
    }
    return 0;
}