#include <bits/stdc++.h>
using namespace std;
int bs(vector <int>&v,int val){
    int l=0;
    int h=v.size()-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(v[mid]==val){
            return mid;
        }
        else if(v[mid]<val){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return h;
}
int ps(vector <int>&bit,int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&(0-i);
    }
}
void update(vector <int>&bit,int i,int x){
    int n=bit.size();
    while(i<=n){
        bit[i]+=x;
        i+=i&(0-i);
    }
}
int main(){
    vector <int> v={2,5,3,6,7,8,1,9};
    vector <int> a1;
    vector <int> a1s;
    vector <int> a2;
    vector <int> a2s;
    int n=v.size();
    vector <int> bit(n+1);
    vector <int> bit2(n+1);
    for(int i=0;i<v.size();i++){
        a1.push_back(2*v[i]+3);
        a1s.push_back(2*v[i]+3);
        a2.push_back(3*v[i]+5);
        a2s.push_back(3*v[i]+5);
        // temp.push_back(v[i]);
    }
    vector <int> c(n);
    vector <int> d(n);
    // sort(temp.begin(),temp.end());
    sort(a1s.begin(),a1s.end());
    sort(a2s.begin(),a2s.end());
    for(int i=0;i<v.size();i++){
        auto atemp=lower_bound(a1s.begin(),a1s.end(),v[n-1-i]);
        int a=atemp-a1s.begin()+1;
        auto btemp=lower_bound(a2s.begin(),a2s.end(),v[i]);
        int b=btemp-a2s.begin()+1;
        cout<<"b: "<<b<<endl;
        // auto pointer=lower_bound(v.begin(),v.end());
        // int j=v.begin()-pointer+1;
        d[n-1-i]=i-ps(bit,a);
        c[i]=ps(bit2,b);
        update(bit,a,1);
        update(bit2,b,1);
    }
    // int ans=0;
    vector <int> ans;
    cout<<"printing a1s: "<<endl;
    for(int i=0;i<n;i++){
        cout<<a1s[i]<<" ";
    }
    cout<<endl<<"printing a2s: "<<endl;
    for(int i=0;i<n;i++){
        cout<<a2s[i]<<" ";
    }
    cout<<endl;
    cout<<"printg c[]: "<<endl;
    for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    cout<<"printg d[] "<<endl;
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        ans.push_back(c[i]*d[i]);
        // cout<<ans[i]<<" ";
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
        // cout<<ans[i]<<" ";
    }
    // cout<<ans;
}