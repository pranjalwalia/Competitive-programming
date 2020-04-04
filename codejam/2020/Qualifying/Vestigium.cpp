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
#define endl			"\n"

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
	int t;
	cin >> t;
	int tc=0;
	while(t--){
		tc++;
		int n;
		cin >> n;
		int a[n][n];
		rep(i , 0 , n){
			rep(j , 0 , n){
				cin >> a[i][j];
			}
		}
		int s=0;
		rep(i , 0 , n){
			rep(j , 0 , n){
				if(i==j)
					s+=a[i][j];
			}
		}
		int r1=0;
		int c1=0;
		unordered_map<int,int>r;
		unordered_map<int,int>c;

		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				r[a[i][j]]++;
				c[a[j][i]]++;
			}
			for(auto itr:r){
				if(itr.ss >1){
					r1++; 
					break;
				}
			}

			for(auto itr2 : c){
				if(itr2.ss > 1){
					c1++;
					break;
				}
			}
			r.clear();
			c.clear();
		}
		cout << "Case #" << tc <<  ": " << s << " " << r1 << " " << c1 << endl;
	}
	
}
