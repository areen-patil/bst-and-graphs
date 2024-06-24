#include <bits/stdc++.h>
using namespace std;
void update(vector <int>&bit,int i,int x){
    int n=bit.size();
    // cout<<"value of i in bit[i] before starting the loop: "<<i<<endl;
    // int c=0;
    while(i<=n){
        // cout<<"value of i in bit[i]: "<<i<<endl;
        bit[i]+=x;
        i+=((i)&(0-i));
        // c++;
        // if(c>100){
        //     break;
        // }
    }
}
int ps(vector <int>&bit,int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=((i)&(0-i));
    }
    return s;
}
int bs(vector <int>& b,int i){
    int l=0,h=b.size()-1;
    // cout<<"called"<<endl;
    while(l<=h){
        int m=(l+h)/2;
        if(b[m]==i){
            // cout<<"paired value of m: "<< m <<" "<<endl;
            return m;
        }
        else if(b[m]<i){
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    // cout<<"RETURNING SOME UNKNOWN VALUE, NOW WHAT TO DO"<<endl<<endl<<endl;
    return h;
}
int numTeams(vector<int>& rating){
    // vector <int> a={2,1,3};
    int s=0;
    vector <int> b;
    for(int i=0;i<rating.size();i++){
        b.push_back(rating[i]);
    }
    sort(b.begin(),b.end());
    int n=rating.size();
    vector <int> bit(n+1);
    vector <int> bit2(n+1);
    vector <int> c(n);
    vector <int> d(n);
    vector <int> e(n);
    vector <int> f(n);
    // for(int i=0;i<n;i++){
    //     cout<<c[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<d[i]<<" ";
    // }
    for(int i=0;i<n;i++){
        int j=bs(b,rating[i])+1;
        c[i]=ps(bit,j);
        e[i]=i-ps(bit,j);
        int k=bs(b,rating[n-1-i])+1;
        // cout<<j<<" "<<k<<endl;
        d[n-1-i]=i-ps(bit2,k);
        f[n-1-i]=ps(bit2,k);
        update(bit,j,1);
        update(bit2,k,1);
        // cout<<"----------------------------------------------------------------"<<endl;;
        // cout<<"c[i] "<<c[i]<<endl;
        // cout<<"d[i] "<<d[i]<<endl;
        // cout<<"e[i] "<<e[i]<<endl;
        // cout<<"f[i] "<<f[i]<<endl;
        // cout<<"---------------------------------------------------------------------"<<endl;;
        // s+=c[i]*d[i];
        // s+=f[i]*e[i];
        // cout<<"S AT EVERY STEP IS: !!!!!!"<<endl;
        // cout<<s;
        // cout<<endl;
    }
    for(int i=0;i<n;i++){
        s+=c[i]*d[i];
        s+=f[i]*e[i];
    }
    // cout<<"final ans:" <<s;
    cout<<s;
}