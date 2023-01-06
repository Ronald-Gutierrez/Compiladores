#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
 
 
int main() {

   int t,x,n;
   //cin >> t;
   t = 1;
   while(t--)
   {
        cin >> n >> x;
        vector<int> price(n+1);
        vector<int> pages(n+1);

        for(int i = 1; i < n+1; i++) cin >> price[i];
        for(int i = 1; i < n+1; i++) cin >> pages[i];
 
        int dp[n+1][x+1];
 
        for(int i = 0; i <= n; i++)
        {
            for(int dinero = 0; dinero <= x; dinero++)
            {
                if(dinero == 0 || i == 0)
                    dp[i][dinero] = 0;
                else
                {
                    int op1 = (i == 1) ? 0 : dp[i-1][dinero];
                    int op2 = (dinero < price[i]) ? 0 : pages[i] + dp[i-1][dinero - price[i]];
                    dp[i][dinero] = max(op1,op2);
                }
            }
        }
 
        cout << dp[n][x];
 
   }
   return 0;
}