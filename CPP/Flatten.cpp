#include<iostream>
#include<utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        pair<TreeNode*, TreeNode*> flattenHelper(TreeNode *root) {

            if(NULL == root){
                pair<TreeNode*, TreeNode*> temp((TreeNode*)0, (TreeNode*)NULL); 
                return temp;
            }else{
                pair<TreeNode*, TreeNode*> left = flattenHelper(root->left);
                pair<TreeNode*, TreeNode*> right = flattenHelper(root->right);
                if(NULL!=left.first && NULL!=right.first){
                    root->right = left.first;
                    left.second->right = right.first;
                    return make_pair(root,right.second);
                }else if (NULL!=left.first){
                    root->right = left.first;
                    return make_pair(root,left.second);
                }else if (NULL!=right.first){
                    root->right = right.first;
                    return make_pair(root,right.second);
                }else{
                    return make_pair(root,root);
                }

            }

        }
        void flatten(TreeNode *root) {

            pair<TreeNode*, TreeNode*> all = flattenHelper(root);

        }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    s.flatten(root);
    cout<<root->val;
    cout<<root->right->val;
    cout<<root->right->right->val;
    return 0;
}



