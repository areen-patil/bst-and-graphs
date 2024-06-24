#include <bits/stdc++.h>
using namespace std;
int find_ind(vector <int>&st,int x,int n){
    int i=0;
    int ss=0;
    int se=n-1;
    if(st[0]<x){
        return -1;
    }
    while(true){
        int m=ss+(se-ss)/2;
        if(ss==se){
            return i-(n-1);
        }
        if(st[i*2+1]>=x){
            i=i*2+1;
            se=m;
        }
        else{
            i=i*2+2;
            ss=m+1;
        }
    }
}
void update(vector <int>&st,int i,int val,int n){
    st[n-1+i]=val;
    i=n-1+i;
    // int p=(i-1)/2;
    // while(p>-1){
    //     st[p]=max(st[2*p+1],st[2*p+2]);
    //     if(p==0){
    //         return;
    //     }
    //     p=(p-1)/2;
    // }
    // while(p>-1){
    //     p=(p-1)/2;
    //     st[p]=max(st[2*p+1],st[2*p+2]);
    // }
    while(i>0){
        i=(i-1)/2;
        st[i]=max(st[2*i+1],st[2*i+2]);
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    int var=1;
    while(var<n){
        var=var*2;
    }
    int extra=var-n;
    int q=n;
    n=n+extra;
    vector <int> st(2*n-1,INT_MIN);
    for(int i=0;i<q;i++){
        int c;
        cin>>c;
        st[n-1+i]=c;
    }
    int j=n-2;
    while(j>-1){
        st[j]=max(st[2*j+1],st[2*j+2]);
        if(j==0){
            break;
        }
        j--;
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(a==2){
            int b;
            cin>>b;
            // cout<<"the val of x is: "<<b<<endl;
            int ans=find_ind(st,b,n);
            cout<<ans<<endl;
        }
        else{
            int b,c;
            cin>>b>>c;
            update(st,b,c,n);
        }
    }




}