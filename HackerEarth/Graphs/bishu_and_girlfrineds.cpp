/*
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
SSSP on a tree --> can use dfs, bfs wouldve been bit faster.
*/

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

#define sd(x)           cin>>x            
#define sd2(x,y)        cin>>x>>y        
#define sd3(x,y,z)      cin>>x>>y>>z

#define tr(x)           cout<<x<<endl
#define tr2(x)          cout<<x<<" "<<y<<endl
#define tr3(x)          cout<<x<<" "<<y<<" "<<z<<endl
#define tr4(x)          cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl
#define tr5(x)          cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<" "<<endl

const int N = 1e5+5;
bool vis[N];
bool flag[N];
int dis[N];
int d_min;
int node_min;
vi g[N];

void dfs(int node , int d){
	vis[node]=1;
	if(flag[node]==1){
		if(d<d_min){
			d_min = d;
			node_min=node;
		}
		if(d==d_min){
			if(node<node_min){
				node_min = node;
			}
		}
	}
	for(int child : g[node]){
		if(!vis[child]){
			dfs(child , d+1);
		}
	}
}

int32_t main(){
	__;
	
  /*
  file();
  input 
  6
  1 2
  1 3
  1 4
  2 5
  2 6
  4
  5
  6
  3
  4
  
  output
  3
  */
	int n; sd(n);
	rep(i , 0, n-1){
		int u,v; sd2(u,v);
		g[u].pb(v); g[v].pb(u);
	}
	node_min = inf;
	d_min = inf;
	int q; sd(q);
	while(q--){
		int x; sd(x);
		flag[x]=1;
	}
	dfs(1,0);
	tr(node_min);
    return 0;
}
