#include<bits/stdc++.h>
using namespace std;

//		MEMOIZED VERSION 


int dp[100][100];

int ks(int w, int wt[], int val[], int i) 
{ 
    if (i < 0) 
        return 0; 
    if (dp[i][w] != -1) 
        return dp[i][w]; 
  
    if (wt[i] > w) {   
        dp[i][w] = ks(w, wt, val, i - 1); 
        return dp[i][w]; 
    } 
    else { 
        dp[i][w] = max(val[i] + ks(w - wt[i], wt, val, i - 1), 
                       ks(w, wt, val, i - 1));   
        return dp[i][w]; 
    } 
} 

int32_t main(){
    memset(dp,-1,sizeof(dp));    
    int val[] = {10,20,30}; 
    int wt[] = {1,1,1}; 
    int W = 2; 
    int n = 3;
    cout << ks(W,wt,val,n);
    return 0;
}
