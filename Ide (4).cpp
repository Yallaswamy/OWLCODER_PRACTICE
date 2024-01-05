#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   vector<vector<int>>v(n,vector<int>(32,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<32;j++){
            if(arr[i]&(1<<j)){
                v[i][j]=1;
            }
        }
    }
    for(int i=0;i<32;i++){
        for(int j=1;j<n;j++){
            v[j][i]+=v[j-1][i];
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        vector<int>v1(32,0);
        int ans=0;
        for(int i=0;i<31;i++){
            if(a==0){
               if(v[b][i]==(b-a+1)/2){
                   ans+=(1<<i);
               }
               continue;
            }
           v1[i]=v[b][i]-v[a-1][i];
           if(v1[i]==(b-a+1)/2) ans+=(1<<i);
        }
        cout<<ans;
        
        
    }
    
    
    
}
