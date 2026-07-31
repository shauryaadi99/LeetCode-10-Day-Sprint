class Solution {
public:
    ListNode* slow_prev;

    ListNode* findMid(ListNode* head) {
        ListNode *slow = head, *fast = head;
        slow_prev = nullptr;

        while (fast && fast->next) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;

        if (!head->next)
            return new TreeNode(head->val);

        ListNode* mid = findMid(head);

        TreeNode* root = new TreeNode(mid->val);

        slow_prev->next = nullptr;   // Split the list

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }
};