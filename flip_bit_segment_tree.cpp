#include <bits/stdc++.h>
using namespace std;
int c=0;
void flip(vector <int>&v,int ss,int se,int l,int r,int i){
    // cout<<"flip function called"<<endl;
    // cout<<"ss: "<<ss<<endl;
    // cout<<"se: "<<se<<endl;
    // cout<<"ss: "<<ss<<" se: "<<se<<" l: "<<l<<" r: "<<r<<endl;
    int m=(ss+se)/2;
    // if(){
    // }
    if(ss==se && ss>=l && se<=r){
        // v[m]=~v[m];
        // cout<< "flipping at: "<<"ss: "<<ss<<"se: "<<se<<endl;
        if(v[i]==0){
            v[i]=1;
        }
        else{
            v[i]=0;
        }
        return;
    }
    if(se<l || ss>r || se<ss){
        return ;
    }
    if(ss>=l && se<=r){
        // v[m]=~v[m];
        // cout<< "flipping at: "<<"ss: "<<ss<<"se: "<<se<<endl;
        if(v[i]==0){
            v[i]=1;
        }
        else{
            v[i]=0;
        }
        return ;
    }
    c++;
    flip(v,ss,m,l,r,2*i+1);
    // cout<<"alternate calls are being made"<<endl;
    // if(c==100){
    //     return ;
    // }
    flip(v,m+1,se,l,r,2*i+2);   
    return ;
    // cout<<"13";
}
int tellme(string s,vector <int> &v,int i){
    int n=s.size();
    if(i>=n){
        return -1;
    }
    int j=n-1+i;
    int val=0;
    // cout<<endl;
    while(j>-1){
        // cout<<"!";
        // cout<<"j: "<<j;
        if(j==(n-1+i)){
            val=v[j];
        }
        else{
            val=val^v[j];
        }
        if(j<=0){
            break;
        }
        j=(j-1)/2;
    }
    if(val==0){
        // cout<<"val: "<<0<<endl;
        if(s[i]=='0'){
            return 0;
        }
        else{
            return 1;
        }
        // return int(s[i])-int(0);
    }
    else{
        // cout<<"val: "<<1<<endl;
        if(s[i]=='0'){
            return 1;
        }
        else{
            return 0;
        }
        // return ~(int(s[i])-int(0));
    }
}
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int var=1;
    int i=0;
    while(var<n){
        i++;
        var=var*2;
        // cout<<"!!!";
    }
    // cout<<endl<<"calculated the extra needed"<<endl;
    if(n!=var){
        int extra=var-n;
        n=extra+n;
    }
    vector <int> st(2*n-1);
    int l=2;
    int r=6;
    flip(st,0,n-1,5,6,0);
    flip(st,0,n-1,1,3,0);
    flip(st,0,n-1,2,5,0);
    
    // flip(st,0,n-1,4,6);
    // for(int i=0;i<st.size();i++){
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
    // flip(st,0,n-1,1,5,0);
    // for(int i=0;i<st.size();i++){
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
    int ind=9;
    int ans=tellme(s,st,ind);
    cout<<"final ans: "<<ans;
}