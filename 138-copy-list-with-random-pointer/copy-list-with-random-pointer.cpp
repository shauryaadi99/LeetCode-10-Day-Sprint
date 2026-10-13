/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        Node* temp = head;
        // copying the node
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
        // setting the random pointers
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node* copyHead = head->next;
        temp = head;
        while (temp) {
            Node* copy = temp->next;
            temp->next = copy->next;
            if (copy->next)
            copy->next = copy->next->next;
            temp= temp->next;
        }
        return copyHead;
    }
};