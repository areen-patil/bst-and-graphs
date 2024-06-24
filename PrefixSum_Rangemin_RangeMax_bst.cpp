#include <bits/stdc++.h>
using namespace std;
struct bst{
    long long int key,value,sum,max,min;
    struct bst *left,*right;
};
void nodeupdate(vector <long long>&a,struct bst*node){
    if(node){
        node->max=node->min=node->key;
        node->sum=node->value;
        if(node->left){
            if(a[node->left->min]<a[node->min]){
                node->min=node->left->min;
            }
            if(a[node->left->max]>a[node->max]){
                node->max=node->left->max;
            }
            node->sum+=node->left->sum;
        }
        if(node->right){
            if(a[node->right->min]<a[node->min]){
                node->min=node->right->min;
            }
            if(a[node->right->max]>a[node->max]){
                node->max=node->right->max;
                node->sum+=node->right->sum;
            }
        }
    }
}
struct bst* createbst(vector <long long>&a,long long l,long long int r){
    struct bst*node=NULL;
    if(l<=r){
        long long int m=(l+r)/2;
        node=(struct bst*)malloc(sizeof(struct bst));
        node->key=m;
        node->value=a[m];
        node->left=createbst(a,l,m-1);
        node->right=createbst(a,m+1,r);
        nodeupdate(a,node);
    }
    return node;
}
void update(vector <long long>&a,struct bst*node,long long int i,long long x ){
    if(node){
        if(node->key>i){
            update(a,node->left,i,x);
        }
        else if(node->key<i){
            update(a,node->right,i,x);
        }
        else{
            a[i]=x;
            node->value=x;
        }
        nodeupdate(a,node);
    }
}
long long int presum(struct bst*node,long long int i){
    long long int sum=0;
    // cout<<"12"<<endl;
    while(node){
        // cout<<"13"<<endl;
        if(node->key>i)node=node->left;
        else if(node->key<i){
            if(node->left)sum+=node->left->sum;
            sum+=node->value;
            node=node->right;
        }
        else{
            if(node->left)sum+=node->left->sum;
            sum+=node->value;
            return sum;
        }
    }
    return 0;
}
long long int rangemin(vector <long long int>&a, struct bst*node,int l,int r,int ss,int se){
    if(node){
        if(ss>=l && se<=r)return node->min;
        else if(se<l && r<ss)return -1;
        else{
            long long int min,m1,m=(ss+se)/2;
            if(node->key>=l && node->key<=r)min=node->key;
            else min=-1;
            m1=rangemin(a,node->right,l,r,m+1,se);
            if(min<0)min=m1;
            if(min>-1 && m1>-1 && a[m1]<a[min])min=m1;
            m1=rangemin(a,node->left,l,r,ss,m-1);
            if(min<0)min=m1;
            if(min>-1 && m1>-1 && a[m1]<a[min])min=m1;
            return min; 
        }
    }
    return -1;
}
long long int rangemax(vector <long long int>&a, struct bst*node,int l,int r,int ss,int se){
    if(node){
        if(ss>=l && se<=r)return node->max;
        else if(se<l && r<ss)return -1;
        else{
            long long int max,m1,m=(ss+se)/2;
            if(node->key>=l && node->key<=r)max=node->key;
            else max=-1;
            m1=rangemax(a,node->right,l,r,m+1,se);
            if(max<0)max=m1;
            if(max>-1 && m1>-1 && a[m1]>a[max])max=m1;
            m1=rangemax(a,node->left,l,r,ss,m-1);
            if(max<0)max=m1;
            if(max>-1 && m1>-1 && a[m1]>a[max])max=m1;
            return max; 
        }
    }
    return -1;
}

// struct bst* findrank(struct bst*node,int r){
//     while(node){
//         if(r==node->count)
//     }

// }
// long long int rangemax(vector <long long int>&a, struct bst*node,int ss,int se,int l,int r){
//     // if(i<l || i>r){
//     //     return INT_MAX;
//     // }
//     // cout<<"infinte loop"<<endl;
//     int m=(ss+se)/2;
//     if(ss>r || se<l){
//         return INT_MIN;
//     }
//     if(ss>=l && se<=r){
//         return node->max;
//     }
//     long long int q=rangemax(a,node->left,ss,m-1,l,r);
//     long long int b=rangemax(a,node->right,m+1,se,l,r);
//     if(q==INT_MIN){
//         return b;
//     }
//     if(b==INT_MIN){
//         return q;
//     }
//     if(a[q]>a[b]){
//         return q;
//     }
//     else{
//         return b;
//     }
//     // if(node->key<l){
//     //     rangemin(a,node->right,l,r);
//     // }
//     // else if(node->key>r){
//     //     rangemin(a,node->left,l,r);
//     // }
//     // else if(i>=l && i<=r){
//     //     return node->min;
//     // }
// }
long long int rangesum(vector <long long int>&a,int x,int y,struct bst*root){
    int ans=presum(root,y)-presum(root,x)+a[x];
    return ans;
}
// long long int average(vector <long long int>&a,int x,int y,struct bst*root){
//     // int sum;
//     // if(x!=0){
//     //     sum=presum(a,y)-presum(a,x-1);
//     // }
//     // else{
//     //     sum=presum(a,y);
//     // }
//     long long int sum=rangesum(a,x,y,root);
//     long long int nums=rank(x)-rank(y)+1;
//     return sum/nums;
// }
// long long int MoreThanAverage(vector <long long int>&a,int x,int y,struct bst*root){
//     long long int temp=average(x,y,root);
//     findrank(a,temp);
// }
int main(){
    vector <long long int> a={4,8,2,5,1,6};
    // vector <long long int>b=a;
    // sort(b.being(),b.end());
    struct bst*root=createbst(a,0,a.size()-1);
    long long i=3;
    // cout<<"bst created"<<endl;
    int ans=presum(root,i);
    // cout<<"prefix sum computed"<<endl;
    cout<<ans<<endl;
    long long int ans1=rangemin(a,root,3,5,0,a.size()-1);
    cout<<"min index: "<<ans1<<endl;
    cout<<"min value "<<a[ans1]<<endl;
    long long int ans2=rangemax(a,root,3,5,0,a.size()-1);
    cout<<"max index: "<<ans2<<endl;
    cout<<"max value: "<<a[ans2]<<endl;

}