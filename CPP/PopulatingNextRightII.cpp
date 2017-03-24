
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(NULL == root)
            return;
        if(NULL == root->left && NULL == root->right)
            return;
        
        TreeLinkNode *head = new TreeLinkNode(-1);
        
        head -> next = NULL;
        
        TreeLinkNode *upper = root;
        
        TreeLinkNode *curr = head;
        
        while(upper)
        {
            
            while(upper)
            {
            if(NULL != upper->left){
                curr -> next = upper->left;
                curr = curr -> next;
            }    
            if(NULL != upper->right){
                curr -> next = upper->right;
                curr = curr -> next;
            }
                upper = upper->next;
            }
            
            curr -> next = NULL;
            upper = head -> next;
            
            curr = head;
        
        }
        
        return;
    }
};
