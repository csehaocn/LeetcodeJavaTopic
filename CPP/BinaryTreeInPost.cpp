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
    TreeNode *buildTreeIter(vector<int>::iterator inBegin, vector<int>::iterator inEnd,vector<int>::iterator postBegin,vector<int>::iterator postEnd) {

        if (inBegin >= inEnd){
            return NULL;
		}

        TreeNode *root = new TreeNode(*(postEnd-1));

        if (1 == inEnd-inBegin){
            return root;
        }
        else{
            vector<int>::iterator it=inBegin;
			int j = *(postEnd-1);
            while(*(postEnd-1) != *it){
                it++;
            }
			cout<<"left";
			int i =it-inBegin;
			root->left = buildTreeIter(inBegin, it, postBegin, postBegin+(it-inBegin)); 
			int k = postEnd-postBegin;
			cout<<"right";
			root->right = buildTreeIter(it+1, inEnd, postBegin+(it-inBegin), postEnd-1);

			return root;
        }
	}
	
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		
		return buildTreeIter(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());

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
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	vector<int> b = vector<int>();
	b.push_back(3);
	b.push_back(2);
	b.push_back(4);
	b.push_back(1);
	Solution c = Solution();
	TreeNode *t = c.buildTree(a,b);
	c.inorder(t);

}
