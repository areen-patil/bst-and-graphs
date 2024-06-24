#include <bits/stdc++.h>
using namespace std;
void update(vector <long long> &st,long long i,long long val,long long n){
    st[n-1+i]=val;
    long long j=n-1+i;
    // j=(j-1)/2;
    // while(j>-1){
    //     st[j]=min(st[j*2+1],st[j*2+2]);
    //     if(j==0){
    //         break;
    //     }
    //     j=(j-1)/2;
    // }
    while(j>0){
        j=(j-1)/2;
        st[j]=min(st[j*2+1],st[j*2+2]);
    }
}
long long pf(vector <long long> &st,long long i,long long n){
    if(i<0 || i>(n-1)){
        return 0;
    }
    long long s=0;
    s+=st[n-1+i];
    i=n-1+i;
    long long p=n-1+i;;
    // long long p=(i-1)/2;
    // while(p>-1){
    //     if(i==(p*2+2)){
    //         s+=st[p*2+1];
    //     }
    //     if(p==0){
    //         break;
    //     }
    //     i=p;
    //     p=(p-1)/2;
    // }
    while(p>0){
        int i=p;
        p=(p-1)/2;
        if(i==(p*2+2)){
            s+=st[p*2+1];
        }
    }
    return s;
}
long long mini(vector <long long> &st,long long ss,long long se,long long l,long long r,long long i){
    long long m=(ss+se)/2;
    if(se<l || ss>r){
        return INT_MAX;
    }
    else if(ss>=l && se<=r){
        return st[i];
    }
    long long a=mini(st,ss,m,l,r,2*i+1);
    long long b=mini(st,m+1,se,l,r,2*i+2);
    long long c=min(a,b);
    return c;
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
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
    vector <long long>  st(2*n-1);
    for(long long i=0;i<q;i++){
        long long c;
        cin>>c;
        st[n-1+i]=c;
    }
    // long long n=st.size();
    for(long long i=0;i<extra;i++){
        st[n-1+q+i]=INT_MAX;
    }

    long long j=n-2;
    while(j>-1){
        st[j]=min(st[j*2+1],st[j*2+2]);
        if(j==0){
            break;
        }
        j--;
    }
    // for(long long i=0;i<st.size();i++){
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
    //-------------------------------------------------------------------
    //-------------------------------------------------------------------
    for(long long i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            update(st,b,c,n);
        }
        else{
            cout<<mini(st,0,n-1,b,c-1,0)<<endl;
        }
    }
}
