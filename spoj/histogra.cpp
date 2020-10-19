    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <cmath>
    #include <string>
    #include <queue>
    #include <bits/stdc++.h>
    #include <stack>
     
    using namespace std;
     
    #define FOR(i,n,m) for(int i=n; i<m; i++)
    #define ROF(i,n,m) for(int i=n; i>m; i--)
    #define pb push_back
    #define ll long long
    #define ri(a)  scanf("%d",&a)
    #define rii(a,b)  scanf("%d %d",&a,&b)
     
     
    /*--------------------------------------------------------------------------------------------------------------------------------------
    --------------------------------------------------------------------------------------------------------------------------------------*/
    ll n,ans,i;
    ll a[200005];
      
    int main()
    {
        //ios_base::sync_with_stdio(false);
        //cin.tie(NULL);
     
        cin>>n;
     
        while(n!=0){
     
            FOR(j,0,n) cin>>a[j];
     
           ans=0,i=0; stack<int> s;
     
            while(i<n){
     
                if(s.empty() || a[s.top()]<=a[i]) s.push(i++);
                else{
                    int minact=s.top(); s.pop();
                    ll x= a[minact]*(s.empty()? i: i-1-s.top());
                    ans=max(ans,x);
                }
     
            }
     
            while(!s.empty()){
                int minact=s.top(); s.pop();
                ll x= a[minact]*(s.empty()? i: i-1-s.top());
                ans=max(ans,x);
            }
     
            cout<<ans<<endl;
     
            cin>>n;
        }
       
    } 
