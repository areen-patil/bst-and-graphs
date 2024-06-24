#include <bits/stdc++.h>
using namespace std;
void update(vector <long long>&st,long long i,long long n){
    st[n-1+i]=!st[n-1+i];
    i=n-1+i;
    long long p=(i-1)/2;
    while(p>-1){
        st[p]=st[2*p+1]+st[2*p+2];
        if(p==0){
            return;
        }
        p=(p-1)/2;
    }
    // i=n-1+i;
    // while(i>0){
    //     i=(i-1)/2;
    //     st[i]=st[2*i+1]+st[2*i+2];
    // }
}
long long find_one(vector <long long>&st,long long k,long long n){
    long long i=0;
    long long ss=0;
    long long se=n-1;
    while(true){
        long long m=(ss+se)/2;
        if(ss==se){
            return i-(n-1);
        }
        if(st[2*i+1]>=k){
            i=i*2+1;
            se=m;
        }
        else{
            k=k-st[2*i+1];
            i=i*2+2;
            ss=m+1;
        }
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
    for(long long i=0;i<q;i++){
        long long c;
        cin>>c;
        st[n-1+i]=c;
    }
    long long j=n-2;
    while(j>-1){
        st[j]=st[2*j+1]+st[2*j+2];
        if(j==0){
            break;
        }
        j--;
    }
    // for(long long i=0;i<st.size();i++){
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
    for(long long i=0;i<m;i++){
        long long a,b;
        cin>>a>>b;
        if(a==1){
            update(st,b,n);
            // for(long long i=0;i<st.size();i++){
            //     cout<<st[i]<<" ";
            // }       
        }
        else{
            long long ans=find_one(st,b+1,n);
            cout<<ans<<endl;
        }
    }
}