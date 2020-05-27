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
int vis[N];
vi g[N];

int bfs(int src , int hops , int n){
	int c=0;
	mii dis;
	queue<int>q;
	q.push(src); vis[src]=1; dis[src]=0;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int child : g[curr]){
			if(!vis[child] && dis[curr]+1 <= hops){
				vis[child]=1;
				dis[child] = dis[curr]+1;
				q.push(child);
			}
		}
	}
	for(auto itr : dis){
		if(itr.ss==hops){
			c++;
		}
	}
	return c;
}

int32_t main(){
	__;
	file();
	int n,m; sd2(n,m);
	rep(i ,0, m){
		int u,v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}	
	int t; cin >> t;
	while(t--){
		int src , hops; sd2(src , hops);
		fill(vis , vis+n+1 , 0);
		cout << bfs(src , hops , n) << endl;
	}
    return 0;
}

/*
input 
9 10
1 2
2 3
1 7
2 4
3 4
4 7
7 8
9 7
7 6
5 6
3
4 2
5 3
2 1 

output
4
4
3

https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/description/
 
*/
