class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *target = head;
        ListNode *end = head;
        
        int size = 1;
        while (end->next != nullptr) {
            end = end->next;
            size++;
            if (size > n + 1)
                target = target->next;
        }

        if (size == n) 
            return head->next;

        if (n == 1) {
            delete target->next;
            target->next = nullptr;
            return head;
        }

        ListNode *t = target->next->next;
        delete target->next;
        target->next = t;
        return head;
    }
};

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