// a smarter way to avoid the NULL pointer is always create a sudo element and delete it later. 
//
// ListNode* result = new ListNode(-1); 

#include"util.hpp"
#include<iostream>

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    ListNode* output = NULL;

    ListNode* curr = NULL;

    int carry = 0;

    ListNode* temp = NULL;

    while(NULL != l1 || NULL != l2)
    {
        int lVal = 0;
        int rVal = 0;
        if(NULL != l1)
            lVal = l1->val;
        if(NULL != l2)
            rVal = l2->val;

        if(NULL == output)
        {
            output = new ListNode((lVal+rVal+carry)%10);
            carry = (lVal+rVal+carry)/10;
            curr = output;
        }
        else
        {
            curr->next = new ListNode((lVal+rVal+carry)%10);
            carry = (lVal+rVal+carry)/10;
            curr = curr -> next;
        }

        if(NULL != l1)
            l1 = l1->next;
        if(NULL != l2)
            l2 = l2->next;
    }

    if(0 != carry)
        curr -> next = new ListNode(1);

    return output;
}

int main()
{
    int arr[] = {1,2,3,4};
    ListNode* l = createList(arr, 4);
    int arr2[] = {2,3,4};
    ListNode* r = createList(arr, 3);

    ListNode* o = addTwoNumbers(l, r);
    //cout << ListToString(l); 
    return 0;
}
