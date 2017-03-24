#include<iostream>

#include"util.hpp"

using namespace std;

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
    ListNode *partition(ListNode *head, int x) {
        
        if(NULL == head)
            return NULL;
        
        ListNode *preL = new ListNode(0);
        ListNode *L = preL;
        
        ListNode *preR = new ListNode(0);
        ListNode *R = preR;
        
        while(NULL != head)
        {
            cout << head->val;
            if(x > head->val){
                L = L->next = head;
            }
            else
            {
                R = R -> next = head;
            }
            head = head -> next;
        }
        L -> next = preR -> next;
        R -> next = NULL;
        delete preL, preR;
        return preL -> next;
        
    }
};

int main()
{
    int A[1] = {1};
    ListNode* head = createList(A, 1);
    Solution S;
    cout << ListToString(S.partition(head, 0));
    return 0;
}
