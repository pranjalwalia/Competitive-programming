/*	Author
@ Pranjal Walia
IIIT Bangalore
*/

/*
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
*/

#include<bits/stdc++.h>
using namespace std;

void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
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
#define sortv(v)        sort(v.begin() , v.end())
#define rsortv(v)       sort(v.rbegin() , v.rend())
#define pw(b,p)         pow(b,p) + 0.1
#define __          	   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b)	   for(int i=a;i<b;i++)
#define repb(i,a,b) 	   for(int i=a;i>=b;i--)
#define endl			   "\n"    

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

void dfsd(int node , int d){        //modified dfs for the sssp tree
    vis[node] = 1;
    dis[node] = d;
    for(auto child : g[node]){
        if(!vis[child])
            dfsd(child , dis[node]+1);
    }
}

void Q2_SSSP(){
int n;sd(n);
    FOR(i ,0 , n-1){
        int u,v; sd2(u,v);
        g[u].pb(u);
        g[v].pb(v);
    }   
    dfsd(1 , 0);
    
    int ans = -1;
    int min_dist = inf;
    int q; sd(q);
    while(q--){
        int id; sd(id);
        if(dis[id] < min_dist){
            min_dist = dis[id];
            ans = id;
        }
        else{
            if(dis[id]==min_dist && id < ans){
                ans = id;
            }
        }
    }
    cout << ans << endl;
}
