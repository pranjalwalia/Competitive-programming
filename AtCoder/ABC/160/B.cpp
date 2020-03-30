include<bits/stdc++.h>
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
#define _ 				ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
int32_t main(){	
	_;
 
	int n;
	cin >> n;
	int ans=0;
	int x = n;
 
	while(x >= 500){
		ans+=(1000*(x/500));
		x = x%500;
	}
 
	while( x >= 5){
		ans += (5 * (x/5));
		x = x%5;
	}
 
	cout << ans << '\n';
}