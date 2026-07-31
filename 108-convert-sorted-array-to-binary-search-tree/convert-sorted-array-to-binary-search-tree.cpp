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
    int lo;
    int hi;
    vector<int> nums;
    TreeNode* convertSortedArrayToBST(int lo, int hi) {
        if (lo > hi)
            return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = convertSortedArrayToBST(lo, mid - 1);
        root->right = convertSortedArrayToBST(mid+1, hi);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        lo = 0;
        hi = nums.size() - 1;
        return convertSortedArrayToBST(lo,hi);
    }
};