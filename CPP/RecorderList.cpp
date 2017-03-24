#include<iostream>
#include<cstddef>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct ListNode* create_list(int* arr, int size)
{
    if (!size){return NULL;}
    else{
        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;
        int pos = 1;
        while(size - pos){
           curr->next = new ListNode(arr[pos]); 
           curr = curr->next;
           pos++;
        }
        return head;
    }
}

void print_L(ListNode *head){
    while(NULL!=head){
        cout<<head->val<<" ";
        head = head-> next;
    }
}

ListNode* reverse(ListNode* head){

    ListNode* pre = NULL; 

    while(NULL!=head){
        
        ListNode* next = head->next;

        head -> next = pre;
        pre = head;
        head = next;
    }

    return pre; 
}

void reorderList(ListNode *head) {

    if(NULL == head)
        return;

    int count = 0;
    ListNode *curr = head;
    while(curr){
        count++;
        curr = curr->next;
    }

    curr = head;
    int step = 0;
    ListNode* pre = curr;
    while(step*2<count){
        pre = curr;
        curr=curr->next;
        step++;
    }
    pre->next = NULL;

    ListNode* dual = reverse(curr);
    ListNode *result = head;
    curr = head;

    while(NULL != dual){
        ListNode* next = curr->next;
        curr -> next = dual;
        curr = dual;
        dual = next;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6};

    ListNode* head = create_list(arr,5); 

    reorderList(head);

    print_L(head);

    return 0;

}

