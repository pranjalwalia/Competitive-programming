/*
  Contains an implemented version of the bfs algorithm for a graph on grid
  https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/robot-in-grid-b7d391f7/description/?layout=old
  
  input:
  3 3 2
  O*O
  OOO
  *OO
  2 2
  1 1
  1 2
  
  out:
  2
  -1

  

*/

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

int mypow(int a, int b){        //(logn) fast exponentiation
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

char g[1001][1001];
bool vis[1001][1001];
int dis[1001][1001];
int n,m,query;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

bool isValid(int x , int y){
	if(x<1 || x>n || y<1 || y>m) return false;
	return true;
}

int32_t main(){	
	__;
	file();
	sd3(n,m,query);
	rep(i, 1 , n+1){
		rep(j , 1 , m+1){
			cin >> g[i][j];
		}
	}
	int sx,sy; sd2(sx,sy);	
	queue<pii>q;
	q.push({sx,sy});
	vis[sx][sy]=1;
	dis[sx][sy]=0;
	while(!q.empty()){
		int currx = q.front().ff;
		int curry = q.front().ss;
		q.pop();
		for(int i=0 ; i<4 ; i++){
			int l = currx+dx[i];
			int r = curry+dy[i];
			if(!vis[l][r] && isValid(l,r) && g[l][r]=='O'){
				vis[l][r]=1;
				dis[l][r] = dis[currx][curry]+1;
				q.push({l,r});
			}
		}
	}
	while(query--){
		int u,v; sd2(u,v);
		if(u==sx && v==sy) cout << 0 << endl;
		else if(dis[u][v]==0) cout << -1 << endl;
		else cout << dis[u][v] << endl;
	}
	return 0;
}




