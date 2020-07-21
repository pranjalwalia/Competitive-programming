#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii              pair<int,int>
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
#define endl			"\n"
#define m(a)		    memset(a,0,sizeof(a))
#define all(x)                          begin(x), end(x)

#define tr(x) cout<<x<<endl;
#define sd(x) cin >> x;
//  Count the number of subarray with the given xor..  //
/*
	store prefix xors..find pairs with p[i]^p[j] = k.
	1. notice if j>i, then p[j]^p[i] = xor(p[i+1]^...p[j]) {xor cancellation prop..}
	2. therefore if p[i] is a valid subarray, then k^p[i] is also valid.
=>	BruteForce: O(N)..
	for(int i=0 ; i<n ;i++){
		int x=0;
		for(int j=i ; j<n; j++){
			x^=a[j];

			if(x==req) ans++;
		}
	}
	tr(ans);
*/

void solve(int a[] ,int k ,int n){
	//method1 => maintaining prefix array..
	int p[n]; p[0]=a[0];
	for(int i=1 ; i<n ;i++) p[i]=p[i-1]^a[i];
	map<int,int>m;
	int ans=0;
	for(int i=0 ; i<n; i++){
		if(p[i]==k) ans++;
		if(m.find(k^p[i]) != m.end()) ans+=(m[p[i]^k]);
		m[p[i]]++;
	}
	tr(ans);
}

int32_t main(){	
	__;
	int a[] = {4,2,2,6,4}; int req = 6; int n = sizeof(a)/sizeof(a[0]);
	int ans=0;
	int x=0;	//maintain running xor..
	map<int,int>m; 
	rep(i,0,n){
		x^=a[i]; 
		if(x==req) ans++;
		if(m.find(req^x) != m.end()) ans+=(m[req^x]);
		m[x]++;
	}
	tr(ans);
	solve(a,req,n);
	return 0;
}




