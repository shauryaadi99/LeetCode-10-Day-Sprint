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
    bool checkMinimaOrMaxima(int prev, int curr, int next) {
        return (prev < curr && curr > next || prev > curr && curr < next);
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *nextNode = NULL;
        int idx = 0;
        int maxDiff = INT_MIN, minDiff = INT_MAX, prevCritical = -1, first = -1;
        while (curr->next) {
            if (prev != NULL && nextNode != NULL) {
                if (checkMinimaOrMaxima(prev->val, curr->val, nextNode->val)) {
                    if (first == -1) {
                        first = idx;
                    } else {
                        minDiff = min(minDiff, idx - prevCritical);
                        
                        maxDiff = idx - first;
                    }
                    prevCritical = idx;
                }
            }
            prev = curr;
            curr = curr->next;
            nextNode = curr->next;
            idx++;
        }
        if (prevCritical == first)
            return {-1, -1};

        return {minDiff, maxDiff};
    }
};