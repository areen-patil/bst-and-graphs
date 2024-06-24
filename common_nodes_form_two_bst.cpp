#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * Definition for a binary tree node.
 */
class Solution {
public:
    unordered_map <int,int> mp;
    vector <int> ans;
    void bst2(TreeNode *node){
        if(node!=NULL){
            bst2(node->left);
            mp[node->val]++;
            bst2(node->right);
        }
    }
    void bst1(TreeNode *node){
        if(node!=NULL){
            bst1(node->left);
            if(mp[node->val]!=0){
                ans.push_back(node->val);
            }
            bst1(node->right);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        bst2(root2);
        bst1(root1);
        return ans;
    }
};