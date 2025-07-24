// https://ac.nowcoder.com/acm/problem/224679

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    int begin = -1;
    int left = 0, right = 0;
    int happy = 0, shy = 0;
    int happyMax = 0, shyMin = 0;

    while(right < n)
    {
        happy += a[right];
        shy += b[right];
        while(right - left + 1 > k)
        {
            happy -= a[left];
            shy -= b[left];
            left++;
        }
        if(right - left + 1 == k)
        {
            if(happy > happyMax)
            {
                begin = left;
                happyMax = happy;
                shyMin = shy;
            }
            else if(happy == happyMax && shy < shyMin)
            {
                begin = left;
                happyMax = happy;
                shyMin = shy;
            }
        }
        right++;
    }
    cout << begin + 1 << endl;
    return 0;
}