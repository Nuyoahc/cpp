// https://ac.nowcoder.com/acm/problem/260770
#include <iostream>

using namespace std;

int n, l, r;
string s;

long long find(int x)
{
    if(x == 0) return 0;
    
    int hash[26] = {0};
    int left = 0, right = 0;
    long long res = 0;
    int kind = 0;
    
    while(right < n)
    {
        if(hash[s[right] - 'a']++ == 0) kind++;
        while(kind > x)
        {
            hash[s[left] - 'a']--;
            if(hash[s[left] - 'a'] == 0) kind--;
            left++;
        }
        res += right - left + 1;
        right++;
    }
    return res;
}

int main()
{
    cin >> n >> l >> r >> s;

    cout << find(r) - find(l - 1) << endl;
    
    return 0;
}