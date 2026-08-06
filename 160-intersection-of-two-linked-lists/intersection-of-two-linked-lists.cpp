/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB)
            return nullptr;

        ListNode *pA = headA, *pB = headB, *temp = headA;
        int lengthA = 0, lengthB = 0;
        while (temp) {
            lengthA++;
            temp = temp->next;
        }
        temp = headB;
        while (temp) {
            lengthB++;
            temp = temp->next;
        }
        if (lengthA > lengthB) {
            int diff = lengthA - lengthB;
            while (diff--)
                pA = pA->next;
        } else {
            int diff = lengthB - lengthA;
            while (diff--)
                pB = pB->next;
        }
        while (pA && pB) {
            if (pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }
};