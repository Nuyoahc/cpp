// https://ac.nowcoder.com/acm/problem/219046

#include <iostream>
#include <algorithm>
using namespace std;
int t;
int arr[6];
int main()
{
    cin >> t;    
    while(t--)
    {
        for(int i = 0; i < 6; i++) cin >> arr[i];
        
        sort(arr, arr + 6);
        if
        (
            arr[0] + arr[1] > arr[2] && arr[3] + arr[4] > arr[5] ||
            arr[0] + arr[2] > arr[3] && arr[1] + arr[4] > arr[5] ||
            arr[0] + arr[3] > arr[4] && arr[1] + arr[2] > arr[5] ||
            arr[0] + arr[4] > arr[5] && arr[1] + arr[2] > arr[3]
        )
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
    return 0;
}