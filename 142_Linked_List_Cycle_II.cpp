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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        // Start traversing from head
        while (head != NULL) {
            // If current node is already in set, it's the start of loop
            if (visited.find(head) != visited.end()) {
                return head;
            }

            // Otherwise, insert current node into set
            visited.insert(head);

            // Move to the next node
            head = head->next;
        }

        // If loop not found, return NULL
        return NULL;
    }
};