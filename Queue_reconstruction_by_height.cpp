#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
    void update(vector <int>&st,int i,int n){
        st[n-1+i]=0;
        i=n-1+i;
        while(i>0){
            i=(i-1)/2;
            st[i]=st[2*i+1]+st[2*i+2];
        }
    }
    int query(vector <int>& st,int k,int n){
        int j=0;
        int ss=0;
        int se=n-1;
        int m;
        while(ss!=se){
            m=(ss+se)/2;
            if(st[2*j+1]>=k){
                j=j*2+1;
                se=m;
            }
            else{
                k=k-st[j*2+1];
                j=j*2+2;
                ss=m+1;
            }
        }
        m=(ss+se)/2;
        return j-n+1; 
    }
    static bool cmp(vector <int>&a,vector <int> &b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        int q=n;
        int var=1;
        while(var<n){
            var=var*2;
        }
        int extra=var-n;
        n=n+extra;
        vector<int> st(2*n-1,0);
        for(int i=0;i<q;i++){
            st[n-1+i]=1;
        }
        vector<vector<int>> ans(people.size());
        int j=n-1;
        while(j>0){
            j--;
            st[j]=st[j*2+1]+st[j*2+2];
        }
        sort(people.begin(),people.end(),cmp); //using a special compare function to sort the array
        for(int i=0;i<people.size();i++){
            int ind=query(st,people[i][1]+1,n);
            ans[ind]=people[i];
            cout<<people[i][0]<<" "<<people[i][1]<<" the value of ind is: "<<ind<<endl;
            update(st,ind,n);
        }
        return ans;
    }
// };