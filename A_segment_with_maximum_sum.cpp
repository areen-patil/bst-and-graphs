#include <bits/stdc++.h>
using namespace std;
long long maxi=INT_MIN;
void create(vector <long long>&st,vector <long long>&mt,long long n){
    long long j=n-2;
    while(j>-1){
        st[j]=st[2*j+1]+st[j*2+2];
        maxi=max(maxi,st[j]);
        j--;
    }
    long long k=n-2;
    while(k>-1){
        mt[k]=max(max(mt[k*2+1],mt[k*2+2]),st[k*2+1]+st[k*2+2]);
        k--;
    }
}
void update(vector <long long>&st,vector <long long>&mt,long long i,long long v,long long n){
    st[n-1+i]=v;
    mt[n-1+i]=v;
    i=n-1+i;
    int p=n-1+i;
    long long temp=i;
    // long long p=(i-1)/2;
    // while(p>-1){
    //     st[p]=st[2*p+1]+st[2*p+2];
    //     maxi=max(maxi,st[p]);
    //     if(p==0){
    //         break;
    //     }
    //     p=(p-1)/2;
    // }
    while(p>0){
        p=(p-1)/2;
        st[p]=st[2*p+1]+st[2*p+2];
    }
    long long p1=n-1+i;
    // while(p1>-1){
    //     mt[p1]=max(max(mt[p1*2+1],mt[p1*2+2]),st[p1*2+1]+st[p1*2+2]);
    //     if(p1==0){
    //         return;
    //     }
    //     p1=(p1-1)/2;
    // }
    while(p1>0){
        p1=(p1-1)/2;
        mt[p1]=max(max(mt[p1*2+1],mt[p1*2+2]),st[p1*2+1]+st[p1*2+2]);
        // mt[p1]=mt[2*p1+1]+mt[2*p1+2];
    }
}
int main(){
    long long n,m;
    cin>>n>>m;
    long long var=1;
    while(var<n){
        var=var*2;
    }
    long long extra=var-n;
    long long q=n;
    n=n+extra;
    vector <long long> st(2*n-1,0);
    vector <long long> mt(2*n-1,0);
    for(long long i=0;i<q;i++){
        long long c;
        cin>>c;
        st[n-1+i]=c;
        mt[n-1+i]=c;
    }
    create(st,mt,n);
    if(mt[0]<0){
        cout<<0<<endl;
    }
    else{
        cout<<mt[0]<<endl;
    }
    // cout<<mt[0]<<endl;;
    for(long long i=0;i<m;i++){
        long long a,b;
        cin>>a>>b;
        update(st,mt,a,b,n);
        if(mt[0]<0){
            cout<<0<<endl;
        }
        else{
            cout<<mt[0]<<endl;
        }
    }
}