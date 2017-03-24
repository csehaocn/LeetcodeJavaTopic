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
    ListNode *reverseKGroup(ListNode *head, int k) {
        
        if(NULL == head)
            return NULL;
        
        vector<ListNode*> vl(k);
        
        ListNode* res = new ListNode(-1);
        
        res-> next = head;
        
        ListNode* curr = head;

        ListNode* l = res;

        while(curr!= NULL)
        {
            int count = 0;
            while(count != k){
                if(NULL != curr){
                    vl[count] = curr;
                    curr = curr -> next;
                }
                else{
                    break;
                }
                count++;
            }
            
            if( k == count){
                l -> next = vl[count-1];
                for(int i = 0; i != count-1; ++i){
                    vl[i+1]-> next = vl[i];
                }
                vl[0]->next = curr;
                l = vl[0];
            }
        }
        
        return res->next;
        
    }
};
