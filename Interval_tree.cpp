#include <bits/stdc++.h>
using namespace std;
struct bst{
    long long int key;
    int height;
    long long int max,high;
    struct bst*left,*right;
};
void update_max(struct bst*node){
    if(node){
        node->max=node->high;
        if(node->left && node->left->max>node->high){
            node->max=node->left->max;
        }
        if(node->right && node->right->max>node->high){
            node->max=node->right->max;
        }
    }

}
struct bst*overlap(struct bst*node,long long int l,long long int r){
    while(node){
        if(l<=node->high && node->key<=r){
            r
        }
    }

}
int main(){

}