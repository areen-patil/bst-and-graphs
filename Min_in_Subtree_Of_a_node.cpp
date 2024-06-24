#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int> parent(n);
    vector <int> val(n);
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        parent[i]=c;
    }
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        val[i]=c;
    }
    vector <int> ans(n);
    for(int i=n-1;i>=0;i--){
        val[parent[i]]=min(val[i],val[parent[i]]);
        ans[i]=val[i];
    }
    for(int i=0;i<n;i++){
        if(i==n-1){
            cout<<ans[i];
        }
        else{
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}