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
    int totsum = 0;
    int num;
    void explorepaths(TreeNode* root, int num) {
        if (!root)
            return;
        // s.push_back(root->val);
        num = num * 10 + root->val;
        if (!root->left && !root->right) {
            totsum += num;
        }
        explorepaths(root->left, num);
        explorepaths(root->right, num);
        num /= 10;
    }
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        num = 0;
        explorepaths(root, num);
        return totsum;
    }
};