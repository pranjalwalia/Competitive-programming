#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define __              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b) 		for(int i=a;i<b;i++)
#define repb(i,a,b) 	for(int i=a;i>=b;i--)
#define inp(a,n)		for(int i=0 ; i<n ; i++){cin >> a[i];} 

int32_t main(){	

	w(t){
		int n; cin >> n;
		vi v(n);
		inp(v,n);
		int ans=0;
		int y=0;
		sort(v.rbegin() , v.rend());
		for(int i=0 ; i<n ; i++){
			if(v[i]-y <= 0){
				y++;
			}
			else{
				ans += (v[i]-y);
				ans%mod;
				y++;
			}
		}
		cout << ans%mod << endl;
	}
	
}