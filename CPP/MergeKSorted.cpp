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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
        int len = lists.size();
        
        if(0 == len)
            return NULL;
        
        // sudo list head
        ListNode* res = new ListNode(0);
        
        ListNode* curr = res;
        
        multimap<int, ListNode*> m;
        
        for(int i = 0; i != len; ++i)
        {
            ListNode* tmp = lists[i];
            if(NULL != tmp){
                m.insert(make_pair(tmp->val, tmp));
            }
        }
        
        while(!m.empty()){
            
            // the smallest one
            auto it = m.begin();
            ListNode* c = it->second;
            curr -> next = c;
            curr = curr -> next;
            
            m.erase(it);
            
            if(c-> next != NULL){
                m.insert(make_pair(c->next->val, c->next));
            }
            
            curr -> next = NULL;
        }
        return res->next;
    }
};
