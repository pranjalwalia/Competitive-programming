/*
  Excellent application of BFS_SSSP: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/description/
  SSSP --> BFS always gives the shortest path when traversing
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
#define sd4(w,x,y,z)      cin>>w>>x>>y>>z


#define tr(x)           cout<<x<<endl
#define tr2(x)          cout<<x<<" "<<y<<endl
#define tr3(x)          cout<<x<<" "<<y<<" "<<z<<endl
#define tr4(x)          cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl
#define tr5(x)          cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<" "<<endl

const int N=1e5+5;
bool vis[N];
int dis[N];
vi g[N];
int pred[N];
/*
  Maintain the pred array to keep track of the pred of node, will be used in print_path() as 
  we traverse up from the destination upto the source.
*/

void bfs(int start , int end){
	queue<int>q;
	q.push(start);
	vis[start]=1;
	dis[start]=0;
	pred[start]=-1;   // init all the pred as -1
	while(!q.empty()){
		int curr = q.front(); q.pop();
		for(int child : g[curr]){
			if(!vis[child]){
				q.push(child);
				vis[child]=1;
				dis[child] = dis[curr]+1;
				pred[child] = curr;

				if(child==end)        // break out of the bfs as soon as we reach the destination
					return;
			}
		}
	}
}	

void print_path(int start , int end){
	int curr = end;    // start from the destination
	vi path;            // store the path
	path.pb(curr);    
	while(pred[curr]!=-1){
		path.pb(pred[curr]);    // push each intermedediary node 
		curr = pred[curr];      // backtrack up the tree
	}
	for(int i=path.size()-1 ; i>=0 ; i--)
		cout << path[i] << " ";   // print the path
}

int32_t main(){
	__;
	file();
  /*
    answer independent of t,c --> observe
    input
    5 5 3 5
    1 2
    1 3
    2 4
    1 4
    2 5
    1 5
    
    output
    3
    1 2 5    
  */
	int n,m,t,c; sd4(n,m,t,c);	
	rep(i , 0 ,m){
		int u,v; sd2(u,v);
		g[u].pb(v); g[v].pb(u);
	}
	fill(pred , pred+n+1 ,-1);              //init all pred as -1
	for(int i=1; i<n+1 ; i++){
		sort(g[i].begin() , g[i].end());      // just for the lexico order of nodes (question specific)
	}
	int start ,end; sd2(start ,end);
	bfs(start , end);
	cout << dis[end]+1 << endl;             // #(nodes) = path.lenght()+1;
	print_path(start , end);                // return path
    return 0;
}
