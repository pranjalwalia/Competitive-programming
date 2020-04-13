/*	Author
@ Pranjal Walia
IIIT Bangalore
*/
// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/description/
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

int vis[1001];      //initialising the graph
vi v[1001];

void dfs(int node){     //dfs on the graph
    vis[node]=1;
    for(int child : v[node]){
        if(!vis[child])
            dfs(child);
    }
}

int32_t main(){
    __;	
    //input the graph
    int n,m,a,b; cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a].pb(b); v[b].pb(a);
    }
    //input complete

// in one go, dfs samples an entire component, therefore each time we get a false on 
// the visited array, we call dfs again and increment the counter

    int c=0;
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            dfs(i); c++;
        }
    }
    cout << c << endl;

    return 0;
}
