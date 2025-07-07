// 求两个集合中相同的元素
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums1 int整型vector 
     * @param nums2 int整型vector 
     * @return int整型vector
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // write code here
        set<int> s1;
        for(auto &e : nums1) s1.insert(e);

        set<int> s2;
        for(auto &e : nums2) s2.insert(e);

        vector<int> res;
        for(auto &e : s1)
        {
            if(s2.find(e) != s2.end())
            {
                res.push_back(e);
            }
        }
        return res; 
    }
};