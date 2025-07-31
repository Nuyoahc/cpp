// https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&ru=/exam/oj
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
 struct TreeNode {
    int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return bool布尔型
     */
    bool IsBalanced_Solution(TreeNode* pRoot) {
        // write code here
        return dfs(pRoot) != -1;
    }
    int dfs(TreeNode* root) // 只有返回值不为 -1 才表示树高
    {
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        if(left == -1) return -1;
        int right = dfs(root->right);
        if(right == -1) return -1;

        return (abs(left - right)) <= 1 ? max(left, right) + 1 : -1;
    }
};