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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode *head = NULL, *curr = NULL;
        int min_h = 0;

        while(1) {
            int min = 10001;
            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] && lists[i]->val < min) {
                    min = lists[i] ->val;
                    min_h = i;
                }
            }
            if(min == 10001)
                return head;

            if(!head) {
                head = lists[min_h];
                curr = head;
            } else {
                curr->next = lists[min_h]; 
                curr = curr->next;
            }
            lists[min_h] = lists[min_h]->next;
        }
    }
};