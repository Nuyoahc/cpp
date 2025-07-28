// https://ac.nowcoder.com/acm/problem/213471

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int left = 1, right = n;
    while(left <= right)
    {
        cout << left << " ";
        left++;
        while(left <= right)
        {
            cout << right ;
            right--;
        }
    }

    return 0;
}