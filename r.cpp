#include <bits/stdc++.h>
using namespace std;
    void update(vector <int>&bit,int i, int x){
        int n=bit.size();
        while(i<=n){
            // cout<<"value of i in bit[i]: "<<i<<endl;
            bit[i]+=x;
            i+=((i)&(0-i));
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
    int bs(vector <int> b,int i){
        int l=0,h=b.size()-1;
        // cout<<"called"<<endl;
        while(l<=h){
            int m=(l+h)/2;
            if(b[m]==i){
                // cout<<"paired value of m: "<< m <<" "<<endl;
                // cout<<"returning the value of m: "<<m<<endl;
                return m;
            }
            else if(b[m]<i){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        // cout<<"IS THIS EVER EVEN HAPPENING !!!!"<<endl;
        return h;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector <int> bit(n+1);
        if(n==1){
            return {0};
        }
        vector <int> b;
        // unordered_map <int,int> mp;
        for(int i=0;i<nums.size();i++){
            // if(mp[nums[i]]==0){
                b.push_back(nums[i]);
                // mp[nums[i]]++;
            // }
        }
        // if(b==nums){
        //     cout<<"true"<<endl;;
        // }
        int j;
        vector <int> ans(n);
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++){
            // j=bs(b,nums[n-1-i])+1;
            // ans[n-1-i]=ps(bit,j);
            // update(bit,j,1);
            j=bs(b,nums[n-1-i])+1;
            int v=ps(bit,j);
            int b;
            if(j-1>0){
                b=ps(bit,j-1);
            }
            int f=v-b;
            ans[n-1-i]=v-f;
            update(bit,j,1);
        }
        // cout<<"work done"<<endl;
        // for(int i=0;i<ans.size();i++){
            // cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"fucking didn't return"<<endl;
        return ans;
    }
    int main(){
    vector <int> nums={0,1,2};
    // reverse(nums.begin(),nums.end());
    vector <int> ans1=countSmaller(nums);
    cout<<"returned form the function"<<endl;
    cout << "ans.size(): "<<ans1.size()<<endl;
    cout<<"ever encountered this statment"<<endl;
    for(int i=0;i<ans1.size();i++){
        cout <<ans1[i]<<" ";
    }    
}
      