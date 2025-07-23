// https://www.nowcoder.com/practice/e8480ed7501640709354db1cc4ffd42a?tpId=37&tqId=21286&ru=/exam/oj

#include <iostream>
#include <string>

using namespace std;

// int main() 
// {
//     string s;
//     int n;
//     cin >> s >> n;
    
//     int max_count = 0;
//     string result = s.substr(0, n);
    
//     for (int i = 0; i <= s.size() - n; ++i) 
//     {
//         int count = 0;
//         for (int j = i; j < i + n; ++j) 
//         {
//             if (s[j] == 'G' || s[j] == 'C') 
//             {
//                 count++;
//             }
//         }
//         if (count > max_count) 
//         {
//             max_count = count;
//             result = s.substr(i, n);
//         }
//     }
    
//     cout << result << endl;
//     return 0;
// }

int main()
{
    string s;
    int n;
    cin >> s >> n;

    int left = 0, right = 0;
    int count = 0;
    int max_count = 0;
    int begin = -1;
    while(right < s.size())
    {
        if(s[right] == 'G' || s[right] == 'C')
        {
            count++;
        }
        while(right - left + 1 > n)
        {
            if(s[left] == 'G' || s[left] == 'C')
            {
                count--;
            }
            left++;
        }
        if(right - left + 1 == n)
        {
            if(count > max_count)
            {
                max_count = count;
                begin = left;
            }
        }
        right++;
    }
    cout << s.substr(begin, n) << endl;

    return 0;
}