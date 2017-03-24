// 1. Line 36, Notice here, forgot to update c at first
#include "util.hpp"
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        
        if(NULL == head)
            return NULL;
        
        if(NULL == head-> next)
            return head;
        
        ListNode* h = new ListNode(0);
    
        h -> next = head;
        
        ListNode* curr = h;
        
        ListNode* a = head;
        ListNode* b = head -> next;
        ListNode* c = b -> next;
        
        while(a != NULL && b != NULL){

            b -> next = a;
            a -> next = c;
            curr -> next = b;
            curr = a;
            a = curr -> next;
            if(a != NULL){
                b = a -> next;

                // Notice here, forgot to update c at first
                
                if(b != NULL)
                {
                    c = b -> next;
                }
                else{
                    c = NULL;
                }
            }
            else
            {
                b = NULL;
                c = NULL;
            }
        }    
        
        return h-> next;
        
    }
};

int main()
{
    int arr[4] = {1,2,3,4};
    ListNode* l = createList(arr, 4);
    Solution S;
    ListNode* r = S.swapPairs(l);
    cout << ListToString(r);
}
