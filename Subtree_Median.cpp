#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int> parent(n);
    vector <int> val(n);
    // vector <int> count(0);
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
    vector <int> count(n,1);
    for(int i=n-1;i>0;i--){
        if(count[parent[i]]%2==0){
            if(val[parent[i]]>val[i]){
                count[parent[i]]+=count[i];
            }
            else{
                count[parent[i]]+=count[i];
                val[parent[i]]=val[i];
            }
        }
        else{
            if(val[parent[i]]<val[i]){
                count[parent[i]]+=count[i];
            }
            else{
                val[parent[i]]=val[i];
                count[parent[i]]+=count[i];
            }
        }
    }
    // vector <int> medain=val;
    // vector <int> ans(n);
    // for(int i=n-1;i>=0;i--){
    //     if(i!=0){
    //         val[parent[i]]+=val[i];
    //         median[i]=
    //         // count[parent[i]]+=val[i];
    //     }
    //     // else{
    //         // count[0]+=1;
    //     // }
    //     ans[i]=val[i];
    // }
    // for(int i=0;i<n;i++){
    //     if(i==n-1){
    //         cout<<ans[i];
    //     }
    //     else{
    //         cout<<ans[i]<<" ";
    //     }
    // }
    for(int i=0;i<n;i++){
        cout<<val[i]<<" ";
    }
    return 0;
}