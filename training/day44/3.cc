// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// const int N = 1e6 + 10;

// int n;
// string s;
// int dp[N]; // dp[i] 表示以第i个字符结尾的最长非递减子序列长度

// int main() 
// {
//     cin >> n >> s;
    
//     int max_len = 0;
//     for (int i = 0; i < n; i++) 
//     {
//         dp[i] = 1;
//         for (int j = 0; j < i; j++) 
//         {
//             if (s[j] <= s[i]) 
//             {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//         max_len = max(max_len, dp[i]);
//     }
    
//     cout << n - max_len << endl;
//     return 0;
// }


// https://ac.nowcoder.com/acm/problem/221822
#include <iostream>
#include <string>

using namespace std;

const int N = 1e6 + 10;

int n;
string s;

char dp[N]; // 长度为N的的所有子序列中最小的末尾
int res;

int main()
{
    cin >> n >> s;

    for(int i = 0; i < n; i++)
    {
        char ch = s[i];
        // ch 放在哪
        if(res == 0 || ch >= dp[res])
        {
            dp[++res] = ch;
        }
        else
        {
            // 二分查找
            int l = 1, r = res;
            while(l < r)
            {
                int mid = (l + r) / 2;
                if(dp[mid] <= ch) l = mid + 1;
                else r = mid;
            }
            dp[l] = ch;
        }

    }
    cout << n - res << endl;

    return 0;
}

