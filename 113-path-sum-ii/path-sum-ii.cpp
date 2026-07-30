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
    vector<vector<int>> res;
    vector<int> path;
    void explore_all_paths(TreeNode* root, int targetSum) {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (root->val == targetSum)
                res.push_back(path);
        }
        explore_all_paths(root->left, targetSum - root->val);
        explore_all_paths(root->right, targetSum - root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return res;
        explore_all_paths(root, targetSum);
        return res;
    }
};