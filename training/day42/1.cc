// https://www.nowcoder.com/practice/a01abbdc52ba4d5f8777fb5dae91b204?tpId=182&tqId=34396&rp=1&ru=/exam/company&qru=/exam/company&sourceUrl=%2Fexam%2Fcompany&difficulty=2&judgeStatus=undefined&tags=&title=
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A int整型vector 
     * @param n int整型 
     * @return int整型
     */
    int getDis(vector<int>& a, int n) {
        // write code here
        int minPrev = a[0];
        int res = 0;
        for(int i = 1; i < n; i++)
        {
            minPrev = min(minPrev, a[i]);
            res = max(res, a[i] - minPrev);
        }
        return res;
    }
};

int main()
{
    Solution s;
    int n = 5;
    vector<int> a = {1, 2, 3, 4, 5};
    cout << s.getDis(a, n) << endl;

    return 0;
}