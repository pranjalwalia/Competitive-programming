#include<bits/stdc++.h>
using namespace std;

int32_t main(){    
        int n; cin >>n;
        int a[n];
        for(int i=0 ; i<n ; i++)
            cin >> a[i];
        sort(a,a+n);
        int ans=0;
        for(int i=0 ; i<n; ++i){
            int count=0;
            for(int j=i+1 ; j<n ;++j){
                if( abs(a[i]-a[j])<=1 )
                    count++;             
            }
            ans = max(ans , count);
        }
        cout << ++ans << endl;
    return 0;
}
