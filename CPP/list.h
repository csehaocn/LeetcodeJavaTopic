#include<vector>
#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

ListNode* makeList(std::vector<int> vec){
    ListNode* head = NULL;
    ListNode** curr = &head;
    if(vec.size())
    {
        for(auto it = vec.begin(); it != vec.end(); it++){
           *curr = new ListNode(*it); 
           curr = &((*curr)->next);
        }
    }
    return head;
}

void pList(ListNode* head){
    ListNode* curr = head;
    while(curr!=NULL){
        std::cout<< curr->val<< " -> "; 
        curr = curr->next;
    }
    std::cout<<"null"<<std::endl;
}
