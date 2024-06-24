#include <bits/stdc++.h>
using namespace std;
int next_smallest(vector <int>&st,vector <int>&a,int i,int n){
    int j=n-1+i;
    int p=(j-1)/2;
    while(p>-1){
        if(j%2==1 && a[st[2*p+2]]<a[i]){
            j=2*p+2;
            while(j<=(n-1)){
                if(a[st[2*j+1]]<a[i]){
                    j=j*2+1;
                }
                else{
                    j=2*j+2;
                }
            }
            return j-n+1;
        }
        else{
            j=p;
            p=(p-1)/2;
        }
    }
    return n;
}
void update(vector <int>&st,vector <int>&a,int i,int x,int n){
    a[i]=x;
    int j=n-1+i;
    int p=(j-1)/2;
    while(p>-1){
        if(a[st[2*p+1]]<=a[st[2*p+2]]){
            st[p]=st[2*p+1];
        }
        else{
            st[p]=st[2*p+2];
        }
        if(p==0){
            break;
        }
        p=(p-1)/2;
    }
}
int main(){
    vector <int> a={1,2,3,4,5,0,7,8};
    int n=a.size();
    int var=1;
    while(var<n){
        var=var*2;
    }
    int extra=var-n;
    int q=n;
    n=n+extra;
    vector <int> st(2*n-1);
    for(int i=0;i<q;i++){
        st[n-1+i]=i;
    }
    int j=n-2;
    while(j>-1){
        if(a[st[2*j+1]]<=a[st[2*j+2]]){
            st[j]=st[2*j+1];
        }
        else{
            st[j]=st[2*j+2];
        }
        if(j==0){
            break;
        }
        j--;
    }
    for(int i=0;i<st.size();i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
    int ans=next_smallest(st,a,3,n);
    cout<<"next smallest after the index i is: "<<ans<<endl;
}