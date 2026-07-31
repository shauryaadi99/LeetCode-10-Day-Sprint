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
        vector<int> prefix(arr.size(), 0);

        prefix[0] = arr[0];
        for (int i = 1; i < prefix.size(); i++) {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        int x = -1, y = -1;
        for (int i = 0; i < prefix.size(); i++) {
            if (arr[i] >= low) {
                x = i;
                break;
            }
        }
        for (int i = prefix.size()-1; i >= 0; i--) {
            if (arr[i] <= high) {
                y = i;
                break;
            }
        }
        if (x == -1 || y == -1)
            return -1;
        return (prefix[y] - prefix[x-1]);
    }
};