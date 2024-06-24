#include <bits/stdc++.h>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
TreeNode* buildTree(vector<int>& nums) {
    if (nums.empty()) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nums.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nums.size()) {
            curr->left = new TreeNode(nums[i++]);
            q.push(curr->left);
        }
        if (i < nums.size()) {
            curr->right = new TreeNode(nums[i++]);
            q.push(curr->right);
        }
    }
    return root;
}
 
void printTree(TreeNode* root) {
    if (!root) {
        return;
    }
      printTree(root->left);
    cout << root->val << " ";
   
    printTree(root->right);
}
stack <int> st;
void LargestAncestor(TreeNode *node){
    if(node==NULL){
        return ;
    }
    if(st.empty()==true){
        st.push(node->val);
    }
    else{
        if(node->val>st.top()){
            st.push(node->val);
        }
        else{
            st.push(st.top());
        }
    }
    LargestAncestor(node->left);
    st.pop();
    if(st.empty()==true){
        cout<<node->val<<"=>"<<node->val<<endl;
    }
    else{
        cout<<node->val<<"=>"<<st.top()<<endl;
    }
    LargestAncestor(node->right);
}
int main() {
    vector<int> nums = { 2,5,3,6,4,1,8,9,7};
    TreeNode* root = buildTree(nums);
    // printTree(root);
    LargestAncestor(root);
    return 0;
}