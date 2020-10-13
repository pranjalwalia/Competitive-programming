#include<bits/stdc++.h>
using namespace std;
int main()
{long long int t,i;
 cin>>t;
 while(t--)
 {long long n,s=0,ans=0;
   cin>>n;
   long long arr[n+1],dp[n+1];
    for(i=1;i<=n;i++)
     {cin>>arr[i];
     if(i%2)
       s+=arr[i];}dp[0]=0;dp[1]=0;
     for(i=2;i<=n;i++)
     {if(i%2)
       dp[i]=max(0ll,arr[i-1]-arr[i]+dp[i-2]);
       else
       dp[i]=max(0ll,arr[i]-arr[i-1]+dp[i-2]);
        ans=max(ans,dp[i]);}
        cout<<ans+s<<endl;
 
 
   }
 }
