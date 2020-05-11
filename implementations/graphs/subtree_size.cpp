#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) 		for(int i=a;i<b;i++)
#define vi              vector<int>
#define __              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb              push_back

const int N = 1e5+9;
int vis[N];
vi g[N];
int subsize[N];
int curr_size;


int sub_dfs(int node){
	int curr_size=1;
	vis[node]=1;
	for(int child : g[node]){
		if(!vis[child]){
			curr_size += sub_dfs(child);
		}
	}
	subsize[node] = curr_size;
	return curr_size;
}

int32_t main(){	
	__;
	int n; cin >> n;
	rep(i ,0, n-1){
		int u,v; cin >> u >> v;
		g[u].pb(v); g[v].pb(u);		
	}
	sub_dfs(1);
	rep(i ,1 , n+1)
		cout << i << " " << subsize[i] << endl;
}
