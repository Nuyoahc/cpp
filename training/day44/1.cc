// https://ac.nowcoder.com/acm/problem/207376
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求最小差值
     * @param a int整型vector 数组a
     * @return int整型
     */
    int minDifference(vector<int>& a) {
        // write code here
        sort(a.begin(), a.end());
        long long res = a[1] - a[0];
        for(int i = 2; i < a.size(); i++)
        {
            res = min(res, (long long)a[i] - a[i - 1]);
        }
        return res;
    }
};