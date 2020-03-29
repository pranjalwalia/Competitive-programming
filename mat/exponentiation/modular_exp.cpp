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

void file(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}

int Mod(int x , int n , int M){			//O(logn)
	if(n==0)
		return 0;
	if(n%2==0){
		int y = Mod(x , n/2 , M);
		return (y*y)%M;
	}
	else return ((x%M) * Mod(x,n-1,M))%M;
}

int32_t main(){	
	//file();
	int x,n;
	cin >> x >> n;
													// To find (x^(n))%M;
	cout << Mod(x , n , mod) << endl;

}