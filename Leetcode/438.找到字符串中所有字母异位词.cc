// Leetcode 438. 找到字符串中所有字母异位词
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int hash1[26] = {0};//统计p中每个字母出现的个数
        for(auto e:p) hash1[e - 'a']++;

        vector<int> res;
        int hash2[26] = {0};//统计窗口中每个字符的个数
        for(int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            hash2[in - 'a']++;//进窗口
            if(hash2[in - 'a'] <= hash1[in - 'a']) count++;//维护count;

            if(right - left + 1 > p.size())//判断
            {
                char out = s[left++];           
                if(hash2[out - 'a'] <= hash1[out - 'a']) count--;//维护count;
                hash2[out - 'a']--;//出窗口
            }
            if(count == p.size()) res.push_back(left);
        }
        return res;
    }
};

int main() 
{
    Solution solution;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = solution.findAnagrams(s, p);
    
    // Output the result
    cout << "Anagram indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
    
    return 0;
}