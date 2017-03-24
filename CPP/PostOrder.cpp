#include<stack>
#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:

        vector<int> postorderTraversal(TreeNode* root) {

            stack<TreeNode*> s1 = stack<TreeNode*>();
            stack<TreeNode*> s2 = stack<TreeNode*>();

            vector<int> result = vector<int>();

            if(!root)
                return result;

            TreeNode* curr = 0;

            s1.push(root);

            while(!s1.empty()){

                curr = s1.top();

                s2.push(curr);
                s1.pop();

                if(NULL!=curr->left)
                    s1.push(curr->left);

                if(NULL!=curr->right)
                    s1.push(curr->right);

            }

            while(!(s2.empty())){
                result.push_back(s2.top()->val);
                s2.pop();
            }

            return result;
        }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(NULL == root)
            return res;
        
        stack<TreeNode*> sta;
        sta.push(root);
        TreeNode* prev = sta.top();
        
        while(!sta.empty()){
            // everything that is going to work is in the stack once.
            TreeNode* top = sta.top();
            // if the node on top of stack is visited, or at the leaf node
            
            if( prev == top->left || prev == top -> right || (NULL == top->left && NULL == top->right) ){
                
                res.push_back(top->val);
                // update previous visited node
                prev = top;
                // pop stack, go to the next element
                sta.pop();
                
            }else
            // if node on top of stack is not visited
            {
            
                // when it is not visited, its left and right child is not visited as well. 
                if(NULL != top->right) sta.push(top->right);
                if(NULL != top->left) sta.push(top->left);
            }
            
        }
        
    }
};

int main(){

    TreeNode *root  = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution s = Solution();
    vector<int> result = s.postorderTraversal(root);
    cout<<"";
}


