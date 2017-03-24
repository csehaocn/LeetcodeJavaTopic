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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(NULL == l1)
            return l2;
        if(NULL == l2)
            return l1;
            
        ListNode* smaller = l1->val < l2->val ? l1 : l2;
        ListNode* bigger = smaller == l1? l2 : l1;
        smaller-> next = mergeTwoLists(smaller->next, bigger);
        return smaller;
    }
};
