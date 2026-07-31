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
public: // in a bst inorder taversal of a binaray seach tree is always sorted
    vector<int> arr;
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root);

        int x = -1, y = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= low) {
                x = i;
                break;
            }
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] <= high) {
                y = i;
                break;
            }
        }
        if (x == -1 || y == -1)
            return -1;
        return accumulate(arr.begin() + x, arr.begin() + y + 1, 0);
    }
};