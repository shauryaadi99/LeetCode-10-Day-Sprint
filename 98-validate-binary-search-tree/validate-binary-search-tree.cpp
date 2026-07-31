/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long minval = LONG_MIN;
    long long maxval = LONG_MAX;
    bool BSTValidate(TreeNode* root, long long minval, long long maxval) {
        if (!root)
            return true;
        if (root->val <= minval || root->val >= maxval)
            return false;
        return BSTValidate(root->left, minval, root->val) &&
               BSTValidate(root->right, root->val, maxval);
    }
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        return BSTValidate(root, minval, maxval);
    }
};