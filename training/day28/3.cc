// https://www.nowcoder.com/practice/da785ea0f64b442488c125b441a4ba4a?tpId=196&tqId=37050&ru=/exam/oj

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
     * @param root TreeNode类 
     * @return int整型
     */
    int res = -1001;
    int maxPathSum(TreeNode* root) {
        // write code here
        dfs(root);

        return res;
    }
    int dfs(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int l = max(0, dfs(root->left));
        int r = max(0, dfs(root->right));

        res = max(res, root->val + l + r);
        return root->val + max(l, r);
    }
};