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
    vector<vector<int>> allSum;
    vector<int> path;
    void explore_all_pathsums(TreeNode* root, int target) {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (target == root->val)
                allSum.push_back(path);
        }
        explore_all_pathsums(root->left, target - root->val);
        explore_all_pathsums(root->right, target - root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        explore_all_pathsums(root, targetSum);
        return allSum;
    }
};