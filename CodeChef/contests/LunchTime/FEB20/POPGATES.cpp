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

int32_t main(){	
	//file();
	w(t){
		int n,k;
		cin >> n >> k;
		mk(a,n,int);
		for(int i=0 ; i<n;  i++){
			char c; cin >> c;
			if(c=='H')
				a[i] = 1;
			else a[i] =0 ;
		}
		int end = n-1;
		while(k--){
			if(a[end]){
				for(int i=0 ; i<=end ; i++){
					if(a[i]==1)
						a[i]=0;

					else a[i]=1;
				}
				end--;
			}
			else end--;
		}
		int c=0;
		for(int i=0;i<=end ; i++){
			if(a[i])
				c++;
		}

		cout << c << endl;
	}

}
