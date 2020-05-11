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

void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}


const int N = 1e5+9;
int vis[N];
vi g[N];
int subsize[N];
int dis[N];
int col[N];

bool dfs_bpg(int node , int c){
	vis[node]=1;
	col[node]=c;

	for(int child : g[node]){
		if(!vis[child]){
			if(dfs_bpg(child , c^1)==false)
				return false;
		}
		else{
			if(col[child]==col[node])
				return false;
		}
	}
	return true;
}

int32_t main(){
	int t; cin >> t;
	for(int tc=1 ; tc<=t ;tc++){
		int n,e; cin >> n>>e;
		rep(i ,0, n+1)
		{
			vis[i]=0;
			g[i].clear();
		}
		rep(i ,	0, e){
			int u,v; cin >> u >> v;
			g[u].pb(v); g[v].pb(u);
		}
		int f=1;
		rep(i ,1 ,n+1){
			if(!vis[i]){
				bool res = dfs_bpg(i , 0);
				if(!res){
					f=0;break;
				}
			}
		}
		cout << "Scenario #" << tc << ":" << endl;
		if(!f){
			cout << "Graph has non bipartite components" << endl;
		}
		else cout << "All components constitute a bioartite graph" << endl;
	}
	return 0;
}
