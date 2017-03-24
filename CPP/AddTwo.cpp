#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {


    public:

        ListNode* addTwoNumbersHelper(ListNode *l1, ListNode *l2, bool carry, ListNode* pre){


            bool carryOrNot = false;

            ListNode* curr = NULL;

            int varA = 0;
            int varB = 0;

            if( NULL != l1)
                varA = l1->val;

            if( NULL != l2)
                varB = l2->val;

            int sum = (varA + varB);

            if(carry)
                sum++;

            int mod = sum%10;

            carryOrNot = (sum>=10)?true:false;

            curr = new ListNode(mod);

            if(NULL != pre){
                pre -> next = curr;
            }else{
                pre = curr;
            }

            ListNode* l1Next ;
            ListNode* l2Next ;

            if(NULL == l1)
                l1Next = l1;
            else
                l1Next = l1->next;
            if(NULL == l2)
                l2Next = l2;
            else
                l2Next = l2->next;

            if( NULL == l1 && NULL == l2 && carry == false){

                return pre;

            }else{

                addTwoNumbersHelper(l1Next, l2Next, carryOrNot, curr);
            }


            return pre;

        }

        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

            ListNode* result = addTwoNumbersHelper(l1, l2, false, NULL);

            return result;
        }
};

int main(){

    Solution s;
    ListNode* a = new ListNode(5);
    ListNode* b = new ListNode(5);
    ListNode * result = s.addTwoNumbers(a, b);
    cout<<"";
}
