#include<stack>
struct TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {


            stack<TreeNode*> s = stack<TreeNode*>();

            s.push(root);

            vector<int> result = vector<int>();

            if(!root)
                return result;

            while(!s.empty()){
            
                TreeNode* curr = s.top();
                s.pop();
                if(NULL!=curr){
                    result.push_back(curr->val);
                    s.push(curr->right);
                    s.push(curr->left);
                }
                
            }

        }
};
