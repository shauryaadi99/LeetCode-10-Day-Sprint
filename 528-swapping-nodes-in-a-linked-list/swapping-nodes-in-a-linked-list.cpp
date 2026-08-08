/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int k;
    ListNode* Kthfrom_end(ListNode* head) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        this->k = k;
        ListNode *firstK = nullptr, *temp = head;
        ListNode* lastK = Kthfrom_end(head);
        int cnt = 1; // k from end = n-k+1 from beg
        while (temp) {
            if (cnt == k) {
                firstK = temp;
                break;
            }
            cnt++;
            temp = temp->next;
        }
        int nodeval = firstK->val;
        firstK->val = lastK->val;
        lastK->val = nodeval;
        return head;
    }
};