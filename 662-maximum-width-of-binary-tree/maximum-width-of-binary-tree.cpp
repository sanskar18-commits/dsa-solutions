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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>>q;
        q.push({root,0});
        int maxwidth = 0;

        while(q.size() > 0){
            unsigned long long currSize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;
            maxwidth = max(maxwidth, (int)(endIdx-stIdx+1));

            for(int i=0; i<currSize; i++){
                TreeNode* curr = q.front().first;
                unsigned long long idx = q.front().second;
                q.pop();
                if(curr->left){
                    q.push({curr->left,2*idx+1});
                } 
                if(curr->right) {
                    q.push({curr->right,2*idx+2});
                }
            }
        }
        return maxwidth;
    }
};