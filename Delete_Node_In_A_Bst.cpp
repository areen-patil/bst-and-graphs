#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* delete1(TreeNode *node,int x){
        if(!node)return node;
        if(node->val>x){
            node->left=delete1(node->left,x);
            return node;
        }
        else if(node->val<x){
            node->right=delete1(node->right,x);
            return node;
        }
        if(node->left && node->right){
            TreeNode *temp=node->left;
            while(temp->right)temp=temp->right;
            node->val=temp->val;
            node->left=delete1(node->left,temp->val);
            return node;
        }
        else{
            TreeNode *child;
            if(!node->left)child=node->right;
            else child=node->left;
            // free(node);
            return child;
        }
        return NULL;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return delete1(root,key);
    }
};