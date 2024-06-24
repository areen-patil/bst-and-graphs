#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector <long long> parent(n);
    vector <long long> val(n);
    for(long long i=0;i<n;i++){
        long long c;
        cin>>c;
        parent[i]=c;
    }
    for(long long i=0;i<n;i++){
        long long c;
        cin>>c;
        val[i]=c;
    }
    vector <long long> ans(n);
    for(long long i=n-1;i>=0;i--){
        if(i!=0){
            val[parent[i]]+=val[i];
        }
        ans[i]=val[i];
    }
    for(int i=0;i<n;i++){
        if(i==(n-1)){
            cout<<ans[i];
        }
        else{
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}