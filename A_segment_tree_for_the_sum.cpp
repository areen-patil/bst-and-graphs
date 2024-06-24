#include <bits/stdc++.h>
using namespace std;
void update(vector <int>&st,int i,int val,int n){
    // int n=st.size();
    st[n-1+i]=val;
    int j=n-1+i;
    // j=(j-1)/2;
    // while(j>-1){
    //     st[j]=st[j*2+1]+st[j*2+2];
    //     if(j==0){
    //         break;
    //     }
    //     j=(j-1)/2;
    // }
    while(j>0){
        j=(j-1)/2;
        st[j]=st[2*j+1]+st[2*j+2];
    }
}
int pf(vector <int>&st,int i,int n){
    if(i<0 || i>(n-1)){
        return 0;
    }
    int s=0;
    s+=st[n-1+i];
    i=n-1+i;
    int p=n-1+i;
    // int p=(i-1)/2;
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
        i=p;
        p=(p-1)/2;
        // st[p]=st[2*p+1]+st[2*p+2];
        if(i==(p*2+2)){
            s+=st[p*2+1];
        }
    }
    return s;
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//correct
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
    vector <int> st(2*n-1,0);
    for(int i=0;i<q;i++){
        int c;
        cin>>c;
        st[n-1+i]=c;
    }
    // int n=st.size();
    // for(int i=0;i<extra;i++){
    //     st[n-1+q+i]=0;
    // }
    int j=n-2;
    while(j>0){
        st[j]=st[j*2+1]+st[j*2+2];
        if(j==0){
            break;
        }
        j--;
    }
    // for(int i=0;i<st.size();i++){
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
//---------------------------------------------------------------
//---------------------------------------------------------------
    //printing prefix sums for all
    // for(int i=0;i<n;i++){
    //     cout<<"for nums "<<st[n-1+i]<<": "<<pf(st,i,n)<<endl;
    // }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        // cout<< a<<" "<<b<<" "<<c<<endl;
        if(a==1){
            update(st,b,c,n);
        }
        else{
            if(c-1<=0){
                cout<<0<<endl;
            }
            else if(b-1<=0){
                cout<< pf(st,c-1,n)<<endl;

            }
            else{
                cout<<pf(st,c-1,n)-pf(st,b-1,n)<<endl;
            }
        }
    }
}
