// https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&ru=/exam/oj
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return bool布尔型
     */
    bool IsContinuous(vector<int>& numbers) {
        // write code here
        int hash[5] = {0};
        for(auto &e : numbers) hash[e]++;
        for(auto &e : hash) if(e > 1) return false;

        int _max = 0, _min = 15;
        for(auto &e : numbers)
        {
            if(e != 0) 
            {
                _max = max(_max, e);
                _min = min(_min, 0);
            }
        }
        return _max - _min <= 4;
    }
};

int main()
{
    Solution s;
    vector<int> numbers = {0, 0, 1, 2, 5};
    cout << (s.IsContinuous(numbers) ? "true" : "false") << endl;
    return 0;
}