// https://www.nowcoder.com/practice/c43a0d72d29941c1b65c857d8ac9047e?tpId=196&tqId=39317&ru=/exam/oj

#include <iostream>
#include <string>
using namespace std;

// "aabcccccaaa"
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param param string字符串 
     * @return string字符串
     */
    string compressString(string param) {
        // write code here
        int left = 0, right = 0;
        string res;
        while(right < param.size())
        {
            while(right + 1 < param.size() && param[right] == param[right + 1])
            {
                right++;
            }
            int len = right - left + 1;
            res += param[left];
            if(len > 1)
            {
                res += to_string(len);
            }
            left = right + 1;
            right = left;
        }
        return res;
    }
};

