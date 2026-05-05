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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        // find length and last node
        ListNode* tail = head;
        int len = 1;
        while(tail->next){
            tail = tail->next;
            len++;
        }

        // make list circular
        tail->next = head;

        // normalize k
        k = k % len;
        int steps = len - k;

        // find new tail
        ListNode* newTail = tail;
        while(steps--){
            newTail = newTail->next;
        }

        // break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};