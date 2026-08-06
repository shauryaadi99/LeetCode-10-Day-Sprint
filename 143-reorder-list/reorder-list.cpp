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
    ListNode* findmiddle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // 1->2->3  4->5->6
        ListNode* middle = findmiddle(head);

        ListNode* rev = reverseList(middle);
        ListNode* curr = head;
        


        while(rev->next!=NULL){
            ListNode* currtemp = curr->next;
            curr->next = rev;

            ListNode* revtemp = rev->next;
            rev->next = currtemp;

            curr = currtemp;
            rev = revtemp;
        }


    }
};