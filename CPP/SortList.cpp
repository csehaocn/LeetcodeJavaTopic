

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
    ListNode *sortList(ListNode *head) {
        
        if(NULL == head)
            return NULL;
        if(NULL == head-> next)
            return head;
            
        ListNode* slow;
        ListNode* fast;
        slow = fast = head;
        while(fast->next){
            
            fast = fast -> next;
            if(fast->next){
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        
        ListNode* l = head;
        ListNode* r = slow-> next;
        slow-> next = NULL;
        l = sortList(l);
        r = sortList(r);
        
        ListNode* preHead = new ListNode(-1);
        ListNode* curr = preHead;
        while(l && r){
            if(l->val > r-> val)
            {
                curr-> next = r;
                r = r-> next;
            }
            else{
                curr-> next = l;
                l = l -> next;
            }
            curr = curr->next;
        }
        
        if(l)
            curr -> next = l;
        else
            curr -> next = r;
            
        return preHead -> next;
        
    }
    /*
    */
    /*
        
    
        pair<ListNode*, ListNode*> quickSortHelper(ListNode *head){
        //As a pointer head, we must copy the head???
        
        if(NULL == head)
            return make_pair((ListNode*)NULL, (ListNode*)NULL);
        
        if(NULL == head->next)
            return make_pair(head, head);
            
        if(NULL == head->next->next)
        {
            ListNode *A = head;
            ListNode *B = head-> next;
            if(A->val > B-> val)
            {
                B-> next = A;
                A-> next = NULL;
                return make_pair(B, A);
            }
            else
            {
                A-> next = B;
                B-> next = NULL;
                return make_pair(A, B);
            }
        }
            

        int pivot = head->val;
        
        ListNode *preHead = new ListNode(-1);
        ListNode *leftHead = new ListNode(-1);
        ListNode *rightHead = new ListNode(-1);
        
        ListNode *leftCurr = leftHead;
        ListNode *rightCurr = rightHead;
        ListNode *curr = head->next;
        
        while(curr){
            if(curr->val > pivot){
                rightCurr -> next = curr;
                rightCurr = rightCurr -> next;
            }
            else
            {
                leftCurr -> next = curr;
                leftCurr = leftCurr -> next;
            }
            curr = curr -> next;
        }
        
        leftCurr -> next = NULL;
        rightCurr -> next = NULL;
        
        pair<ListNode*, ListNode*> left = quickSortHelper(leftHead-> next);
        pair<ListNode*, ListNode*> right = quickSortHelper(rightHead-> next);
        
        head-> next = right.first;
        
        
        ListNode* l;
        
        if(NULL == left.second)
            l = head;
        else{
            left.second->next = head;
            l = left.first;
        }
        return make_pair(l, right.second);
        }
public:
    ListNode *sortList(ListNode *head) {
        if(NULL == head)
            return NULL;
        
        if(NULL == head->next)
            return head;
        
        return quickSortHelper(head).first;
        
    }*/
};
