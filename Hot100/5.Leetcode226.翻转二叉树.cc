#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if (root == nullptr) 
        {
            return nullptr;
        }
        struct TreeNode* left = invertTree(root->left);
        struct TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

int main()
{
    Solution solution;
    TreeNode* root = new TreeNode(4);   
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    TreeNode* invertedRoot = solution.invertTree(root);

    // Output the inverted tree structure
    cout << "Inverted tree root value: " << invertedRoot->val << endl;
    return 0;
}