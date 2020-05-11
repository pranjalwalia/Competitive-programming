/*
 * find the sssp 
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
*/

void bfs(int src){
	queue<int>q;
	q.push(src);
	vis[src]=1;
	dis[src]=0;

	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int child : g[curr]){
			if(!vis[child]){
				q.push(child);
				dis[child] = dis[curr]+1;
				vis[child]=1;
			}
		}
	}
}

int32_t main(){
	__;
	//file();
	w(t){
		int n,e; cin >> n >> e;
		rep(i ,0 ,n+1){
			vis[i]=0; g[i].clear();
		}
		rep(i ,0, e){
			int u,v; cin >> u >> v;
			g[u].pb(v); g[v].pb(u);
		}
		bfs(1);
		cout << dis[n] << endl;
	}
}
