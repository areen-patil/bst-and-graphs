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
        long long k;
        cin>>k;
        val[i]=k;
    }
    // vector <int> ans(n);
    for(long long i=0;i<n;i++){
        if(i!=0){
            val[i]+=val[parent[i]];
        }
        // ans[i]=val[i];
    }
    for(long long i=0;i<n;i++){
        // if(i==(n-1)  ){
        //     cout<<val[i];
        // }
        // else{
        cout<<val[i]<<" ";
        // }
    }
    return 0;
}