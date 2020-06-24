#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define ii              pair<int,int>
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


void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

bool is_pal(string s) {return equal(all(s), s.rbegin());}

int mypow(int a, int b){        //(logn) --> faster than recursive --> binary expo
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
}

int32_t main(){	
	__;
	file();
	w(t){
		int n,m; sd2(n,m);
		int a[n][m];

		rep(i ,0, n) rep(j ,0,m) sd(a[i][j]);
		map<int,int>ma;
		vi odd;
		rep(i ,0 ,n) rep(j ,0, m) ma[a[i][j]]++;
		int odd_count=0;

		for(auto itr : ma)
		{
			if(itr.ss&1){
				odd_count++;
				odd.pb(itr.ff);
				ma[itr.ff]--;
			}
		}

		if(((m&1) and odd_count > n) || (odd_count!=0 and !(m&1))){
			cout << -1 << endl;
			continue;
		}

		auto itr = ma.begin();

		for(int i=0 ; i<n ;i++){
			for(int j=0 ; j<m/2 ; j++)
			{
				if(j != m-1-j){
					while(itr->ss == 0) itr++;

					a[i][j] = itr->ff;
					a[i][m-j-1] = itr->ff;
					itr->ss-=2;
				}
			}
		}

		for(auto itr : ma){
			if(itr.ss != 0){
				for(int j=0; j<itr.ss ; j++){
					odd.pb(itr.ff);
				}
			}
		}

		if(m&1){
			for(int i=0 ; i<n ; i++){
				a[i][m/2]=odd[i];
			}
		}

		rep(i ,0 ,n){
			rep(j ,0 ,m) cout << a[i][j] << " ";
			cout << endl;
		}
	}
}
