#include<stack>
struct TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {

            stack<TreeNode*> s = stack<TreeNode*>();

            TreeNode* curr = root;

            vector<int> result = vector<int>();

            if(!root)
                return result;

            while(true){
                if(NULL!=curr){
                    s.push(curr);
                    curr = curr->left;
                }
                else
                {
                    if(s.empty()){
                        break;
                    }
                    else{
                        curr = s.top();  
                        s.pop();
                        result.push_back(curr->val); 
                        curr = curr -> right;
                    }
                }

            }


        }
};
