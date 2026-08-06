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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, NULL);
        ListNode* temp = head;
        int n = 0;
        while (temp) {
            temp = temp->next;
            n++;
        }
        int eachBucketNodes = n / k;
        int remNodes = n % k;
        ListNode *prev = NULL, *curr = head;

        for (int i = 0; curr && i < k; i++) {
            res[i] = curr;
            for (int i = 0; i < eachBucketNodes + (remNodes > 0 ? 1 : 0); i++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            remNodes--;
        }
        return res;
    }
};