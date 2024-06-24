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
    int mini=INT_MAX;
    void mn(TreeNode *node){
        if(node==NULL){
            return ;
        }
        else{
            if(node->left){
                int a=node->left->val-node->val;
                if(a<0){
                    a=a*-1;
                }
                mini=min(mini,a);
            }
            if(node->right){
                int b=node->right->val-node->val;
                if(b<0){
                    b=b*-1;
                }
                mini=min(mini,b);
            }
        }
        mn(node->right);
        mn(node->left);
    }
    int getMinimumDifference(TreeNode* root) {
        mn(root);
        return mini;
    }
};