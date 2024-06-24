#include <bits/stdc++.h>
using namespace std;
struct node{
    long long val=0;
    struct node*left=NULL;
    struct node*right=NULL;

};
void update(struct node*node){
    if(node==NULL){
        return ;
    }
    if(node->left){
        node->left->val=min(node->val,node->left->val);
        update(node->left);
    }
    if(node->right){
        node->right->val=min(node->val,node->right->val);
        update(node->right);
    }
    // if(node->right!=NULL && node->left!=NULL){
    //     node->val=min(node->val,node->left->val);
    //     node->val=min(node->val,node->right->val);
    // }
    // else if(node->left){
    //     node->val=min(node->val,node->left->val);
    // }
    // else if(node->right){
    //     node->val=min(node->val,node->right->val);
    // }
}
void Level_Order_Traversal(struct node* root,vector <long long>&ans){
    struct node* current = new struct node();
    current = root;
    deque<struct node*> que;
    que.push_back(current);
    while(!que.empty()){
        if(current->left != nullptr){
            que.push_back(current->left);
        } 
        if(current->right != nullptr){
            que.push_back(current->right);
        }
        ans.push_back(que.front()->val);
        que.pop_front();
        current = que.front();
    }
}
// void sumarray(struct node*node,vector <long long>&ans){

// }
int main(){
    long long n;
    cin>>n;
    vector <long long> parent(n);
    vector <long long> val(n);
    for(long long i=0;i<n;i++){
        long long c;
        cin>>c;
        parent[i]=c;
    }
    for(long long i=0;i<n;i++){
        long long c;
        cin>>c;
        val[i]=c;
    }
    // cout<<"creating tree(n)"<<endl;
    vector <struct node*>tree(n);
    struct node*root;
    for(long long i=0;i<n;i++){
        tree[i]=new struct node();
        // cout<<"valid"<<endl;
        if(i==0){
            root=tree[i];
        }
        tree[i]->val=val[i];
        if(i!=0){
            if(tree[parent[i]]->left!=NULL){
                tree[parent[i]]->right=tree[i];
            }
            else{
                tree[parent[i]]->left=tree[i];
            }
        }
    }
    // cout<<"created tree"<<endl;
    update(root);
    // cout<<"update succesful"<<endl;
    vector <long long> ans;
    Level_Order_Traversal(root,ans);
    // cout<<"level order succesfull"<<endl;
    for(long long i=0;i<n;i++){
        cout <<ans[i]<<" ";
    }
}