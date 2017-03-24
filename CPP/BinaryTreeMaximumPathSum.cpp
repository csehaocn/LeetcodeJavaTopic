#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2{

    int DFS(TreeNode *root, int &mmax){

        if(NULL==root)
            return 0;

        int l = DFS(root->left,mmax);
        int r = DFS(root->right,mmax);

        mmax = max(mmax, max(0,l)+max(0,r)+root->val);

        return max(max(l+root->val,r+root->val),root->val); 
    }

    public:
    int maxPathSum(TreeNode *root) {

        int mmax=0;
        return DFS(root,mmax);
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
    // The helper compute the max sum from root to left
    
    unordered_map<TreeNode*, int> treeNodeMap;
    
    int maxPathSumHelper(TreeNode *root){
        
        if(NULL == root)
            return 0;
        
        if(treeNodeMap.find(root) != treeNodeMap.end())
        {
        //    cout <<"y" << endl;
         //   cout << root -> val << endl;
            treeNodeMap[root] = max(root->val, max(0, root->val+max(maxPathSumHelper(root->left), maxPathSumHelper(root->right))));
          //  cout << treeNodeMap[root]<< endl;
        }
        
        return treeNodeMap[root];
    }
    
public:
    int maxPathSum(TreeNode *root) {
        int res = root -> val;
 //       cout << res << endl;        
        cout << "a" << maxPathSumHelper(root->left) << endl;
        cout << "b" << maxPathSumHelper(root->left) << endl;
        res = max(res, root -> val + maxPathSumHelper(root->left) + maxPathSumHelper(root->right));
//        cout << res << endl;        
        
        if(NULL != root -> left)
            res = max(res, maxPathSum(root->left));
        
        if(NULL != root -> right)
            res = max(res, maxPathSum(root->right));
            
        return res;
    }
};

// My solution go through the tree twice. however, with a member varable, you can just look up the maximum left right pass and go through the maximum at one loop.
// This is called, find the maximum path rooted at the current node. 
// What is interesting here is no table to record is needed. If think carefully, each function at root is called only once.

int main(){
Solution s;
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
cout << "eee" << endl;
cout << s.maxPathSum(root)<< endl;
return 0;
}
