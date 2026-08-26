/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int search(vector<int>& inorder,int val, int left, int right){
        for(int i=left; i<= right; i++){
            if(val == inorder[i]){
                return i;
            }

        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int l, int r) {
        if(l > r){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preIdx]);
        preIdx++;


        int idIdx = search(inorder, preorder[preIdx-1],l,r);

        root->left = helper(preorder, inorder, preIdx,l,idIdx-1);
        root->right = helper(preorder, inorder, preIdx, idIdx+1, r);

    return root;
    
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;

        return helper(preorder, inorder,preIdx,0,inorder.size()-1);



    }
};