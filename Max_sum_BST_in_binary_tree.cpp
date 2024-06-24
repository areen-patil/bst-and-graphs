#include <bits/stdc++.h>
using namespace std;
// /**
//  * Definition for a binary tree node.
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
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public: 
//     TreeNode *global=NULL;
//     int func(TreeNode *node){
//         if(node==NULL){
//             return INT_MIN;
//         }
//         int a=func(node->left);
//         int b=func(node->right);
//         if(a==INT_MIN && b==INT_MIN){
//             if(global==NULL){
//                 global=node;
//                 return node->val;
//             }
//             else{
//                 if(global->val<node->val){
//                     global=node;
//                 }
//             }
//         }
//         else if(a!=INT_MAX && b!=INT_MAX && a!=INT_MIN && b!=INT_MIN){
//             if(node->val>node->left->val && node->val<node->right->val){
//                 node->val=a+b+node->val;
//                 if(node->val>global->val){
//                     global=node;
//                 }
//                 return node->val; 
//             }
//             else{
//                 return INT_MAX;
//             }
//         }
//         else if(a!=INT_MIN && b==INT_MIN && a!=INT_MAX && b!=INT_MAX){
//             if(node->val>node->left->val){
//                 node->val=a+node->val;
//                 if(node->val>global->val){
//                     global=node;
//                 }
//                 return node->val; 
//             }
//             else{
//                 return INT_MAX;
//             }
//         }
//         else if(a==INT_MIN && b!=INT_MIN && a!=INT_MAX && b!=INT_MAX){
//             if(node->right==NULL){
//                 cout <<"NULL";
//             }
//             cout <<endl<<b;
//             if(node->val<node->right->val){
//                 cout <<"came inside this"<<endl;
//                 cout<<node->val<<endl;
//                 node->val=b+node->val;
//                 cout <<node->val<<endl;
//                 cout << global->val;
//                 if(node->val>global->val){
//                     global=node;
//                     cout<<endl<<global->val;
//                 }
//                 return node->val; 
//             }
//             else{
//                 return INT_MAX;
//             }
//         }
//         else{
//             return INT_MAX;
//         }
//         return node->val;
//     }
//     int maxSumBST(TreeNode* root) {
//         int temp=func(root);
//         cout <<"temp: "<<temp<<endl;
//         if(global==NULL){
//             cout <<"wrong code";
//         }
//         cout<<"final: "<<global->val;
//         if(global->val>=0)return global->val;
//         else return 0;
//     }
// };
 
//WORKING BUT TIME LIMIT EXCEEDED

class Solution {
public: 
    int maxi=INT_MIN;
    int sum(TreeNode*node){
        if(node==NULL){
            return 0;
        }
        int a=sum(node->left);
        int b=sum(node->right);
        return a+b+node->val;
    }
    void func(TreeNode * node){
        if(node!=NULL){
            // int a=validateleft(node->left,node);
            // int b=validateright(node->right,node);
            // if(a==1 && b==1){
            bool a=isValidBST(node);
            if(a==true){
                int ans=sum(node);
                maxi=max(maxi,ans);
            }
            func(node->left);
            func(node->right);
        }
    }
    vector <int> v;
    void validate(TreeNode*node){
        if(node==NULL)return;
        validate(node->left);
        v.push_back(node->val);
        validate(node->right);
    }
    bool isValidBST(TreeNode* root) {
        int c=0;
        validate(root);
        for(int i=0;i<v.size()-1;i++){
            if(v[i]<v[i+1]){
                c++;
            }
        }   
        if(c==v.size()-1){
            v.clear();
            return true;
        }
        else{
            v.clear();
            return false;
        }
    }
    // int validateleft(TreeNode *node,TreeNode *root){
    //     int a=1;
    //     if(node==NULL){
    //         return 1;
    //     }
    //     if(node->val>root->val){
    //         a=0;
    //     }
    //     int p=validateleft(node->right,root);
        
    //     int q=validateleft(node->left,root);
    //     if(a==0){
    //         return a;
    //     }
    //     if(p==0){
    //         return p;
    //     }
    //     if(q==0){
    //         return q;
    //     }
    //     return 1;
    // }
    // int validateright(TreeNode *node,TreeNode *root){
    //     int a=1;
    //     if(node==NULL){
    //         return 1;
    //     }
    //     if(node->val<root->val){
    //         a=0;
    //     }
    //     int p=validateright(node->right,root);
    //     int q=validateright(node->left,root);
    //     if(a==0){
    //         return a;
    //     }
    //     if(p==0){
    //         return p;
    //     }
    //     if(q==0){
    //         return q;
    //     }
    //     return 1;
    // } 
    int maxSumBST(TreeNode* root) {
        func(root);
        cout <<maxi;
        if(maxi>=0){
            return maxi;
        }
        else{
            return 0;
        }
    }
};