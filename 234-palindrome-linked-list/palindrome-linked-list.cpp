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
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reversedHead(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head, *fast = head;
        ListNode* middle = findmiddle(head);
        ListNode* Headofreversed = reversedHead(middle);
        ListNode* temp = head;
        while (Headofreversed) {
            if (temp->val != Headofreversed->val)
                return false;

            temp = temp->next;
            Headofreversed = Headofreversed->next;
        }
        return true;
    }
};