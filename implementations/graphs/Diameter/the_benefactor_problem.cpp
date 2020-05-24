/*	Author --> @Pranjal Walia   IIIT Bangalore  

The Benefactor Problem --spoj
https://www.spoj.com/problems/BENEFACT/
*/
#include<bits/stdc++.h>
using namespace std;

#define ff              				first
#define ss              				second
#define int             				long long
#define pb              				push_back
#define mp              				make_pair
#define pii             				pair<int,int>
#define vi              				vector<int>
#define mii             				map<int,int>
#define pqb             				priority_queue<int>
#define pqs             				priority_queue<int,vi,greater<int> >
#define setbits(x)      				__builtin_popcountll(x)
#define zrobits(x)      				__builtin_ctzll(x)
#define mod             				1000000007
#define inf             				1e18
#define mem(a,x,n)					    memset(a,x,sizeof(a))		//initialise only 0 ans -1 with memset
#define ps(x,y)         				fixed<<setprecision(y)<<x
#define mk(arr,n,type)  				type *arr=new type[n];
#define w(x)            				int x; cin>>x; while(x--)
#define sortv(v)        				sort(v.begin() , v.end())
#define rsortv(v)       				sort(v.rbegin() , v.rend())
#define pw(b,p)         				pow(b,p) + 0.1
#define __          	   				ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b)	   					for(int i=a;i<b;i++)
#define repb(i,a,b) 	   				for(int i=a;i>=b;i--)
#define endl			   				"\n"    

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

int mypow(int a, int b){	//(logn) --> faster than recursive --> binary expo
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

const int N = 1e5+5;
vector<pii>g[N];
int vis[N];
int dis[N];

int dijkstras(int source , int n){
    // lol this is the opposite of dijkstras
    priority_queue<pii , vector<pii> ,greater<pii>>pq;
    pq.push({0 , source});
    dis[source]=0;
    while(!pq.empty()){
        int u = pq.top().ss;
        pq.pop();
        if(!vis[u]) vis[u]=1;

        for(auto child : g[u]){
            int v = child.ff;
            int w = child.ss;

            if(w + dis[u] < dis[v]){
                dis[v] = dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
    int mx=0;
    int id;
    for(int i=1 ; i<=n ; i++){
    //    cout << dis[i] << " ";
        if(mx < dis[i]){
            mx = dis[i];
            id = i;
        }
    }
    return id;
}

int32_t main(){
    __;
    file();
    w(t){
        int n; sd(n);
        rep(i , 0 , n+1)g[i].clear();
        fill(dis , dis+n+4 , inf); fill(vis , vis+n+5 , 0);
        rep(i ,0, n-1){
        int u,v,w; sd3(u , v ,w);
        g[u].pb({v,w});
        g[v].pb({u , w});
        }
        int y = dijkstras(1,n);
        fill(vis,vis+n+5,0);
        fill(dis , dis+n+5 , inf);
        int id = dijkstras(y,n);
        int ans = dis[id];
        tr(ans);
    }
    return 0;
}
