#include<iostream>
#include "util.hpp"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {

        int diff_count = 0;
        if(NULL == head || 0 == n)
            return head;
        ListNode* l = head;
        ListNode* r = head;
        
        while(r != NULL)
        {
            r = r-> next;

            if( diff_count < n+1)
            {
                ++ diff_count;
            }
            else
            {
                l = l -> next;
            }
        }

        if(diff_count < n+1)
            return head->next;
        else
        {
            l -> next = l-> next->next; 
            return head; 
        }
    }
};

int main(){

}
