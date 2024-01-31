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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode* r = new ListNode(0);
        ListNode* c = r;

        while (p1 && p2) {
            if (p1->val <= p2->val){
                c->next = p1;
                c = c->next;
                p1 = p1->next;
            } else {
                c->next = p2;
                c = c->next;
                p2 = p2->next;
            }
        }
        if (p1)
            c->next = p1;
        if (p2)
            c->next = p2;
        return r->next;
    }
};