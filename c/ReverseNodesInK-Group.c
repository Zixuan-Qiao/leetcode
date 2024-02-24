/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    struct ListNode* h = head;
    struct ListNode* last_t = NULL;
    struct ListNode* r = NULL;
    bool first = true;
    while(1) {
        r = h;
        for(int i = 1; i < k; i++) {
            r = r->next;
            if(!r) {
                return head;
            }
        }

        struct ListNode *prev = h;
        struct ListNode *curr = prev->next;

        for(int i = 1; i < k; i++) {
            prev->next = curr->next;
            curr->next = h;
            h = curr;
            curr = prev->next;
        }

        if(first) {
            head = h;
            first = false;
        } else {
            last_t->next = h;
        }

        last_t = prev;

        if(!curr) {
            return head;
        }
        h = curr;
    }
}