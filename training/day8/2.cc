// https://www.nowcoder.com/practice/eac1c953170243338f941959146ac4bf?tpId=196&tqId=37143&ru=/exam/oj
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * max increasing subsequence
     * @param arr int整型vector the array
     * @return int整型
     */
    int MLS(vector<int>& arr) {
        // write code here
        sort(arr.begin(), arr.end());

        int res = 0;
        for(int i = 0; i < arr.size();)
        {
            int j = i + 1, count = 1;
            while(j < arr.size())
            {
                if(arr[j] - arr[j - 1] == 1)
                {
                    count ++;
                    j++;
                }
                else if(arr[j] - arr[j - 1] == 0) 
                {
                    j++;
                }
                else 
                {
                    break;
                }
            }
            res = max(count,  res);
            i = j;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << sol.MLS(arr) << endl;
    return 0;
}   