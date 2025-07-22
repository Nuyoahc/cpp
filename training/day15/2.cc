#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<int, int> cntMap;

bool check(int x)
{
    int g = 0;
    for (auto &[a, b] : cntMap)
    {
        g += b / x + (b % x == 0 ? 0 : 1);
    }
    return g <= m;
}

int main()
{

    cin >> n >> m;
    int hmax = 0; // 统计声部最多的人数
    for (int i = 0; i < n; ++i)
    {
        int e;
        cin >> e;
        if (++cntMap[e] > hmax)
            hmax = cntMap[e];
    }

    int kind = cntMap.size();
    if (kind > m)
    {
        cout << -1;
    }
    else
    {
        // 暴力查找
        //         for (int i = 1; i <= hmax; ++i) {
        //             if (check(i) ){
        //                 cout << i;
        //                 break;
        //             }
        //         }
        // 二分查找
        int left = 1, right = hmax;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        cout << left;
    }

    return 0;
}
