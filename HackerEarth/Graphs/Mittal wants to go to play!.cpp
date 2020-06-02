/*
https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/mittal-wants-to-go-to-play/
*/

/*
    LOOK FOR A FASTER IMPLEMENTATION...
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
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
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


const int N = 1001;
vector<pii>g[N];
int vis[N];
int dis[N];

void dijkstras(int s){
    priority_queue<pii, vector<pii> ,greater<pii>> pq;
    pq.push(mp(0 , s));
    dis[s]=0;

    while(!pq.empty()){
        pii p = pq.top();
        pq.pop();
        int u = p.ss;
        if(!vis[u]){
            vis[u]=1;
            for(auto child : g[u]){
                int other_node = child.ff;
                int weight = child.ss;
                if(dis[other_node] > dis[u] + weight){
                    dis[other_node] = dis[u] + weight;
                    pq.push(mp(dis[other_node] , other_node));
                }
            }
        }
    }    
}

int32_t main(){	
	__;
	file();
   /*
   inp:
  1
  5 5
  1 2 2
  2 3 4
  3 4 5
  4 5 1
  1 4 7
  3
  4 20
  5 21
  3 5
  output:
  6 5 0
   */
  
	w(t){
		int n,m; sd2(n,m);
		fill(vis , vis+n+1 ,0);
		rep(i ,0 ,n+1){
			g[i].clear();
		}
		rep(i , 0 , m){
			int u,v,w; sd3(u,v,w);
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		fill(dis , dis+n+1 , inf);
		dijkstras(1);
		int q; sd(q);
		while(q--){
			int node , k;sd2(node,k);
			//cout << dis[node] << endl;
			if(k-2*dis[node] < 0){
				cout << 0 << endl;
			}
			else cout << k-2*dis[node] << endl;
		}
	}
	return 0;
}




