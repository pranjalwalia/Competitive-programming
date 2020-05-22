/*	Author --> @Pranjal Walia   IIIT Bangalore  */
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
vector<pii> g[N];
int vis[N];
int dis[N];

void dijkstras(int s , int dest){
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

    /*
    // print the shortest distance of all nodes from the source i.e consider every node as the destination
    cout << "Shortest Distance of nodes from source..." << endl;
    rep(i , 0, N+1){
        cout << i << " " << dis[i] << endl;
    } 
    */
    cout << dis[dest] << endl;    
}

int32_t main(){
    __;
    file();
    /*  SAMPLE INPUT 
        9 14
        0 8
        0 1 4
        0 7 8
        1 2 8
        1 7 11
        2 3 7
        2 8 2
        2 5 4
        3 4 9
        3 5 14
        4 5 10
        5 6 2
        6 7 1
        6 8 6
        7 8 7 

        OUTPUT IS 14 FOR 0 -> 8.
    */
        // Init graph
        int n,e; sd2(n,e);
        int source; sd(source);
        int destination; sd(destination);        
        fill(vis , vis+n+1 , 0);
        fill(dis , dis+n+1 , inf);
        for(int i=0 ; i<e+5 ;  i++){
            g[i].clear();
        }
        // Graph input
        rep(i,  0, e-1){
            int u,v,l; sd3(u,v,l);
            g[u].pb(mp(v,l));
            g[v].pb(mp(u,l));
        }

        dijkstras(source,destination);
    return 0;
}

