#include <bits/stdc++.h>
using namespace std;
struct bst{
    long long int key,sum,count;
    struct bst *left,*right;
    int height;
};
void nodeupdate(struct bst*node){
    int sum=0;
    node->sum=node->key;
    node->count=1;
    int h1=-1,h2=-1;
    if(node->right){
        node->sum+=node->right->sum;
        node->count+=node->right->count;
        h1=node->height;
    }
    if(node->left){
        node->sum+=node->left->sum;
        node->count+=node->left->count;
        h2=node->height;
    }
    node->height=max(h1,h2)+1;
}
struct bst* createbst(vector <long long>&a,long long l,long long int r){
    struct bst*node=NULL;
    if(l<=r){
        long long int m=(l+r)/2;
        node=(struct bst*)malloc(sizeof(struct bst));
        node->key=a[m];
        // node->value=a[m];
        node->left=createbst(a,l,m-1);
        node->right=createbst(a,m+1,r);
        nodeupdate(node);
    }
    return node;
}
long long int findcount(struct bst*root,struct bst*node){
    if(root->key<node->key){
        root=root->right;
    }
    else if(root->key>node->key){
        root=root->left;
    }
    else{
        return root->count;
    }
}
void update(struct bst*root,struct bst*node){
    if(root==node){
        nodeupdate(root);
        return;
    }
    if(root->key<node->key){
        update(root->right,node);
    }
    else{
        update(root->left,node);
    }
    nodeupdate(root);
}
long long int ranks(struct bst*node,long long int x){
    int r=0;
    while(node){
        if(node->key==x){
            if(node->right){
                r+=node->right->count+1;
                return r;
            }
            else{
                r+=1;
                return r;
            }
        }
        else if(node->key<x){
            node=node->right;
        }
        else{
            if(node->right){
                r+=node->right->count+1;
            }
            else{
                r+=1;
            }
            node=node->left;
        }
    }
    return r;
}
struct bst* findranks(struct bst*node,int r){
    if( node->right!=NULL && r==node->right->count+1){
        return node;
    }
    else if(node->right==NULL && r==1){
        return node;
    }
    // if(node->right){
    if(node->right->count+1>r){
        return findranks(node->right,r);
    }
    if(node->right->count+1<r){
        return findranks(node->left,r-node->right->count-1);
    }
}
long long int presum(struct bst*node,long long int i,int ss,int se){
    // int m=(ss+se)/2;
    // if(se<i || ss>i){
    //     return 0;
    // }
    int s=0;
    while(node){
        int m=(ss+se)/2;
        if(m==i){
            if(node->left){
                s+=node->left->sum+node->key;
                return s;
            }
            else{
                s+=node->key;
                return s;
            }
        }
        else{
            if(m<i){
                ss=m+1;
                s+=node->key;
                if(node->left){
                    s+=node->left->sum;
                }
                node=node->right;
            }
            else{
                se=m-1;
                node=node->left;
            }
        }
    }
    return -1;
}
long long int rangesum(vector <long long int>&a,long long int x,long long int y,struct bst*root){
    int ans=presum(root,y,0,a.size()-1)-presum(root,x,0,a.size()-1)+a[x];
    return ans;
}
long long int average(vector <long long int>&a,long long int x,long long int y,struct bst*root){
    // int sum;
    // if(x!=0){
    //     sum=presum(root,y,0,a.size()-1)-presum(root,x-1,0,a.size()-1);
    // }
    // else{
    //     sum=presum(root,y,0,a.size()-1);
    // }
    long long int sum=rangesum(a,x,y,root);
    long long int nums=ranks(root,a[x])-ranks(root,a[y])+1;
    return sum/nums;
}
long long int MoreThanAverage(vector <long long int>&a,int x,int y,struct bst*root){
    long long int temp=average(a,x,y,root);
    long long ans=ranks(root,temp)-ranks(root,a[y]);
    return ans;
}
int main(){
    vector <long long int> a={15,19,26,32,39,64,29,52,73,93,85};
    sort(a.begin(),a.end());
    struct bst* root=createbst(a,0,a.size()-1);
    int ans0=presum(root,3,0,a.size()-1);
    cout<<"the presum of index 3 is : "<<ans0<<endl;
    long long int ans1=ranks(root,32);
    cout<<"ranks of 32 is: "<<ans1<<endl;
    struct bst* ans2=findranks(root,7);
    cout <<"the elemnt with ranks 7 is : "<<ans2->key<<endl;
    long long int ans3=rangesum(a,1,3,root);
    cout << "the range sum between 1 and 3 is: "<<ans3<<endl;
    long long int ans4=average(a,1,3,root);
    cout <<"the average between numbers 1 and 3 is: "<<ans4<<endl;
    long long int ans5=MoreThanAverage(a,1,3,root);
    cout <<"the numebr greater than the average of 1 and 3, between them are: "<<ans5<<endl;
}