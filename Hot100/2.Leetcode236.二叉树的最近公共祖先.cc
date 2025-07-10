#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root;

        // 递归在左子树
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        // 递归在右子树
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 左右子树都找到，说明当前节点就是
        if (left != nullptr && right != nullptr)
            return root;

        // 只有左子树找到，返回左子树
        if (left != nullptr)
            return left;
        // 只有右子树找到，返回右子树
        return right;
    }
};

int main()
{
    Solution solution;
    //          3
    //         / \
    //        5   1
    //       / \   / \
    //      6   2 0   8
    //         / \
    //        7   4
    // 创建二叉树
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode *p = root->left; // 5
    TreeNode *q = root->right; // 1
    TreeNode *ancestor = solution.lowestCommonAncestor(root, p, q);
    if (ancestor != nullptr)
        cout << "Lowest Common Ancestor: " << ancestor->val << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;
    // 清理内存
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;   
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
