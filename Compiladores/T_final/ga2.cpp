#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
// // Iterative
// int iterative(int n,int C,vector<int>&w,vector<int>&p){
//    int dp[n+1][C+1];
 
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=C;j++){
//            if(i==0||j==0) dp[i][j]=0;
//            else if(j<w[i-1]) dp[i][j]=dp[i-1][j];
//            else dp[i][j]=max(dp[i-1][j],p[i-1]+dp[i-1][j-w[i-1]]);
//        }
//    }
 
//    return dp[n][C];
 
// }
 
 
 
//Recursive
int dp[1005][100005]={0};
 
int recursive(int n,int C,vector<int> &w,vector<int> &p){
   
   if(n<0 || C<0) return 0;
 
   if(dp[n][C]!=0) return dp[n][C];
 
   int op1=0,op2=0;
   if(w[n]<=C) op1=p[n] + recursive(n-1,C-w[n],w,p);
   op2=recursive(n-1,C,w,p);
 
   return dp[n][C]=max(op1,op2);
}
 
    
signed main(){
    fast;
    int n,C;
    cin>>n>>C;
    vector<int> w(n),p(n);
    vector<vector<int>> dp(n,vector<int>(C,0));
 
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>p[i];
    
     cout<<recursive(n-1,C,w,p)<<"\n";
 
    //cout<<iterative(n,C,w,p)<<"\n";
    return 0;
 
}