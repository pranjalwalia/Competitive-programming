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

void file(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	#endif
}

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define deb3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

/*
	AtCoder ABC 173 (https://www.youtube.com/watch?v=6Vwt-jGW2bQ) => check out for C
		A. Simple problem, just a simple observation.
		B. Another simple implementation using map.

		C. Real good stuff => ** ALL POSSIBLE COMBINATIONS USING BIT MANIPULATION ** (https://www.geeksforgeeks.org/iterating-over-all-possible-combinations-in-an-array-using-bits/)
			All possible comb are 2^(rows+columns) - 1.
			for i in range [0,2^rows):
				for j in range[0,2^col):
					1. copy original input into test input.
					2. color(i,j) the test array...the set bits of i(n bit because of n rows) => rows to color and set bits of j(m bit because m columns) => cols to color
					3. after coloring, check if #(black tiles)==k, if yes => ans++;
						
*/

void A(){
	int n; sd(n);
	if(n%1000){
		cout << 1000-(n%1000) << endl;
	}
	else{
		cout << 0 << endl;
	}
}

void B(){
		int n; sd(n); map<string,int>m;
	m["AC"]=0;
	m["TLE"]=0;
	m["WA"]=0;
	m["RE"]=0;
	rep(i ,0,n){
		string s; cin>>s;
		m[s]++;
	}
	cout << "AC" << " x " << m["AC"] << endl; 
	cout << "WA" << " x " << m["WA"] << endl; 
	cout << "TLE" << " x " << m["TLE"] << endl; 
	cout << "RE" << " x " << m["RE"] << endl; 
}

int n,m,k;
char a[7][7];
char b[7][7];

void copy(){
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			b[i][j] = a[i][j];
		}
	}	
}

void color(int i , int j){
	//iterate through the rows and check if a row x is enabled, if yes color the row.
	for(int x=0; x<n; x++){
		//if the xth bit is set, then we have to color the xth row.
		if(i&(1<<x)){
			for(int y=0; y<m ;y++){
				b[x][y]='$';
			}
		}
	}

	//iterate through the columns, if a column is enabled, color the entire column.
	for(int y=0 ; y<m ; y++){
		if(j&(1<<y)){
			//if the yth bit is set, then we have to color the yth column.
			for(int x=0 ; x<n ; x++){
				b[x][y]='$';
			}
		}
	}
}

bool check(){
	int c=0;
	for(int i=0 ; i<n ; i++){
		for(int j=0; j<m ; j++){
			if(b[i][j]=='#'){
				c++;
			}
		}
	}
	if(c==k){
		return 1;
	}
	else return 0;	
}

void C()
{
	sd3(n,m,k);
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			sd(a[i][j]);
		}
	}
	int ans=0;
	for(int i=0 ; i<(1<<n) ; i++){
		for(int j=0 ; j<(1<<m) ; j++){
			copy();
			color(i,j);
			if(check()){
				ans++;
			}
		}
	}
	tr(ans);
}

bool cmp(int x , int y)
{
	return x>y;
}

int32_t main(){	
	__;
	file();
	return 0;
}




