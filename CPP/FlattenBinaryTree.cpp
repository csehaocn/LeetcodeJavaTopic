/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    pair<TreeNode*, TreeNode*> flatterHelper(TreeNode *root){
        
        if(NULL == root)
            return make_pair((TreeNode*)NULL, (TreeNode*)NULL);
        
        if(NULL == root->left && NULL == root->right)
            return make_pair(root, root);
            
        pair<TreeNode*, TreeNode*> l = flatterHelper(root->left);
        
        pair<TreeNode*, TreeNode*> r = flatterHelper(root->right);
        
        root->left = NULL;
        if(NULL == l.second){
            root->right = r.first;
            root->left = NULL;
            return make_pair(root,r.second);
        }
        else if(NULL == r.first)
        {
            root->right = l.first;
            return make_pair(root,l.second);
        }
        else
        {
            root->right = l.first;
            root->left = NULL;
            l.second -> right = r.first;
            return make_pair(root, r.second);
        }
            
    }
    
public:
    void flatten(TreeNode *root) {
        pair<TreeNode*, TreeNode*> pt = flatterHelper(root);
        return;
    }
};
