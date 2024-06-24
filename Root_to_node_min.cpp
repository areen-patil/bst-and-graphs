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
        int k;
        cin>>k;
        val[i]=k;
    }
    // vector <int> ans(n);
    for(int i=0;i<n;i++){
        if(i!=0){
            val[i]=min(val[parent[i]],val[i]);
        }
        // ans[i]=val[i];
    }
    for(int i=0;i<n;i++){
        // if(i==(n-1)  ){
        //     cout<<val[i];
        // }
        // else{
        cout<<val[i]<<" ";
        // }
    }
    return 0;
}