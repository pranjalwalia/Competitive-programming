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
#define inp(a,n)		for(int i=0 ; i<n ; i++) cin >> a[i]

void file(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}

int bs(int a[] , int s , int e, int x){
	if(s<=e){
		int m = (s+e)/2;
		if(a[m]==x)
			return m;
		else if(a[m] > x)
			return bs(a,s,m-1,x);
		else return bs(a,m+1,e,x);
	}
	return -1;
}

int32_t main(){	
	__;
	int n; cin >> n;
	mk(a,n,int);
	mk(b,n,int);
	mk(c,n,int);

	rep(i,0,n){
		cin >> a[i];
	}
	rep(i,0,n){
		cin >> b[i];
	}
	rep(i,0,n){
		c[i] = b[i]-a[i];
	}

	int ans=0;
	sort(c,c+n);

	rep(i,0,n){
		auto itr = lower_bound(c + i + 1, c+n , -c[i]);
		int p = itr-c;
		ans+=(p-(i+1));
	}

	cout << ans << endl;


}