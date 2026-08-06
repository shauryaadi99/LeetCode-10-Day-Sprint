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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        ListNode* slow = &dummy;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        // nth node is slow->next
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return dummy.next;
    }
};