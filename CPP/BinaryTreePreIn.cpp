/**************************************************************************
 * 
 *   File :       BinaryTreePreIn.cpp
 *   Created:     10/29/13
 *   Author:      Hao Wang
 *
 * ------------------------------------------------------------------------
 *
 * COPYRIGHT AIMLAB UNIVERSITY OF OREGON, 2013.
 * All rights reserved.
 * 
 * ------------------------------------------------------------------------
 *   
 * Revision history:
 *  10/29/13  Hao first issue
 *
 *************************************************************************/

/**************************************************************************
 * Description:  
 *
 * Argument:     
 *
 * Return value:
 *************************************************************************/

#include <cstddef>
#include <vector>
#include <iostream>
using namespace std;

 struct TreeNode {
      	int val;
 		TreeNode *left;
 		TreeNode *right;
 		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {

public:
    TreeNode *buildTreeIter(vector<int>::iterator preBegin, vector<int>::iterator preEnd,vector<int>::iterator iBegin,vector<int>::iterator inEnd) {

        if (preBegin == preEnd){
            return NULL;
		}
        TreeNode *root = new TreeNode(*preBegin);

        if (1 == preEnd-preBegin){
            return root;
        }
        else{
            vector<int>::iterator it=iBegin;
            int countLength = 0;
            while(*preBegin != *it){
                it++;
                countLength++;
            }
			root->left = buildTreeIter(preBegin+1, preBegin+countLength+1, iBegin, it); 
			root->right = buildTreeIter(preBegin+countLength+1, preEnd, it+1, inEnd);

			return root;
        }
	}
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		
		return buildTreeIter(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
        
/*
        if (0 == preorder.size()){
            return NULL;

		}
        TreeNode *root = new TreeNode(preorder[0]);
        

        if (1 == preorder.size()){
            return root;
        }
        else{
            vector<int>::iterator it=inorder.begin();
            int countLength = 0;
            while(preorder[0] != *it){
                it++;
                countLength++;
            }
			vector<int> il = vector<int>(preorder.begin()+1, preorder.begin()+countLength+1);
			vector<int> ir = vector<int>(inorder.begin(),it);

			root->left = buildTree(il,ir); 

			vector<int> pl = vector<int>(preorder.begin()+countLength+1, preorder.end());
			vector<int> pr = vector<int>(it+1,inorder.end());

			root->right = buildTree(pl,pr); 
			return root;
        }
*/
	}
	void inorder(TreeNode *root){ 
		if (NULL == root){
		}	
		else
		{
			inorder(root->left);				
			cout<<root->val;
			inorder(root->right);				
		}
	}


};

int main(){

	vector<int> a = vector<int>();
	a.push_back(4);
	a.push_back(3);
	a.push_back(1);
	a.push_back(2);
	a.push_back(5);
	vector<int> b = vector<int>();
	b.push_back(1);
	b.push_back(3);
	b.push_back(2);
	b.push_back(4);
	b.push_back(5);
	Solution c = Solution();
	TreeNode *t = c.buildTree(a,b);
	c.inorder(t);

}

	void inorder(TreeNode *root){ 
		if (NULL == root){
		}	
		else
		{
			inorder(root->left);				
			cout<<root->val;
			inorder(root->right);				
		}
	}
