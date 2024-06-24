// #include <bits/stdc++.h>
// using namespace std;
// void update(vector <int>&v,int i,int val,int n){
//     v[n-1+i]=val;
//     int j=n-1+i;
//     j=(j-1)/2;
//     while(j>-1){
//         v[j]=min(v[j*2+1],v[j*2+2]);
//         mp[j]=0;
//         if(v[j*2+1]==v[j*2+2]){
//             mp[j]+=2;
//         }
//         else{
//             mp[j]+=1;
//         }
//         if(j==0){
//             break;
//         }
//         j=(j-1)/2;
//     }
// }
// int pf(vector <int>&v,int i,int n){
//     if(i<0 || i>(n-1)){
//         return 0;
//     }
//     int s=0;
//     // s+=v[i];
//     int p=(i-1)/2;
//     while(p>-1){
//         if(i==(p*2+2)){
//             s+=v[p*2+1];
//         }
//         if(p==0){
//             break;
//         }
//         i=p;
//         p=(p-1)/2;
//     }
//     return s;
// }
// vector <int>  mini(vector <int>&v,int ss,int se,int l,int r,int i){
//     int m=(ss+se)/2;
//     if(se<l || ss>r){
//         return {INT_MAX,0};
//     }
//     else if(ss>=l && se<=r){
//         return {v[i];
//     }
//     vector <int> a=mini(v,ss,m,l,r,2*i+1);
//     vector <int> b=mini(v,m+1,se,l,r,2*i+2);
//     int c=min(a[0],b[0]);
//     c=min(c,v[i]);
//     int count=0;
//     if(c==a[0]){
//         count+=a[1];
//     }
//     if(c==b[0]){
//         count+=b[1];
//     }
//     if(c==v[i]){
//         count+=v[i];
//     }
//     // return min(c,v[i]);
//     return {c,count};

// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int var=1;
//     while(var<n){
//         var=var*2;
//     }
//     int extra=var-n;
//     unordered_map<int,int> mp;
//     int q=n;
//     n=n+extra;
//     vector <int> v(2*n-1);
//     for(int i=0;i<q;i++){
//         int c;
//         cin>>c;
//         v[n-1+i]=c;
//     }
//     // int n=v.size();
//     for(int i=0;i<extra;i++){
//         v[n-1+q+i]=INT_MAX;
//     }
//     int j=n-2;
//     while(j>-1){
//         v[j]=min(v[j*2+1],v[j*2+2]);
//         if(v[j*2+1]==v[j*2+2]){
//             mp[j]+=2;
//         }
//         else{
//             mp[j]+=1;
//         }
//         if(j==0){
//             break;
//         }
//         j--;
//     }
//     for(int i=0;i<v.size();i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
//     for(int i=0;i<m;i++){
//         int a,b,c;
//         cin>>a>>b>>c;
//         if(a==1){
//             update(v,b,c,n);
//         }
//         else{
//             cout<<mini(v,0,n-1,b,c-1,0)<<endl;;
//         }
//     }
// }



// long long pf(vector <long long> &st,long long i,long long n){
//     if(i<0 || i>(n-1)){
//         return 0;
//     }
//     long long s=0;
//     s+=st[n-1+i];
//     i=n-1+i;
//     long long p=n-1+i;;
//     // long long p=(i-1)/2;
//     // while(p>-1){
//     //     if(i==(p*2+2)){
//     //         s+=st[p*2+1];
//     //     }
//     //     if(p==0){
//     //         break;
//     //     }
//     //     i=p;
//     //     p=(p-1)/2;
//     // }
//     while(p>0){
//         int i=p;
//         p=(p-1)/2;
//         if(i==(p*2+2)){
//             s+=st[p*2+1];
//         }
//     }
//     return s;
// }

#include <bits/stdc++.h>
using namespace std;
void update(vector <vector<long long>> &st,long long i,long long val,long long n){
    st[n-1+i][0]=val;
    long long j=n-1+i;
    // j=(j-1)/2;
    // while(j>-1){
    //     st[j]=min(st[j*2+1],st[j*2+2]);
    //     if(j==0){
    //         break;
    //     }
    //     j=(j-1)/2;
    // }
    while(j>0){
        j=(j-1)/2;
        st[j][0]=min(st[j*2+1][0],st[j*2+2][0]);
        st[j][1]=0;
        if(st[j][0]==st[2*j+1][0]){
            st[j][1]=st[2*j+1][1];
        }
        if(st[j][0]==st[j*2+2][0]){
            st[j][1]+=st[2*j+2][1];
        }
    }
}
vector<long long> mini(vector <vector<long long>> &st,long long ss,long long se,long long l,long long r,long long i){
    long long m=ss+(se-ss)/2;
    if(se<l || ss>r){
        return {INT_MAX,1};
    }
    else if(ss>=l && se<=r){
        return {st[i][0],st[i][1]};
    }
    vector <long long> a=mini(st,ss,m,l,r,2*i+1);
    vector <long long> b=mini(st,m+1,se,l,r,2*i+2);
    long long c=min(a[0],b[0]);
    long long count=0;
    if(c==a[0]){
        count+=a[1];
    }
    if(c==b[0]){
        count+=b[1];
    }
    return {c,count};
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
int main(){
    long long n,m;
    cin>>n>>m;
    long long var=1;
    while(var<n){
        var=var*2;
    }
    long long extra=var-n;
    long long q=n;
    n=n+extra;
    vector <vector<long long>>  st(2*n-1,vector <long long>(2,0));
    // cout<<"is there a problem in declaration itself"<<endl;
    for(long long i=0;i<q;i++){
        long long c;
        cin>>c;
        st[n-1+i][0]=c;
        st[n-1+i][1]=1;
    }
    // long long n=st.size();
    // cout<<"first part done"<<endl;
    for(long long i=0;i<extra;i++){
        st[n-1+q+i][0]=INT_MAX;
        st[n-1+q+i][1]=1;
    }
    // cout<<"taken inputs"<<endl;
    // long long j=n-2;
    long long j=n-1;
    while(j>0){
        j--;
        st[j][0]=min(st[j*2+1][0],st[j*2+2][0]);
        if(st[j][0]==st[2*j+1][0]){
            st[j][1]+=st[2*j+1][1];
        }
        if(st[j]==st[j*2+2]){
            st[j][1]+=st[2*j+2][1];
        }
        // if(j==0){
        //     break;
        // }
        // j--;
    }
    // for(long long i=0;i<st.size();i++){
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
    //-------------------------------------------------------------------
    //-------------------------------------------------------------------
    // cout<<"going to start the calling"<<endl;
    for(long long i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            update(st,b,c,n);
        }
        else{
            vector <long long> ans=mini(st,0,n-1,b,c-1,0);
            cout<<ans[0]<<" "<<ans[1]<<endl;
        }
    }
}
