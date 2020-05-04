/*
	1. Efficient implementation in O(N)
       	2. Algo --> run dfs and find the d_max from any random node, now on the ending node of d_max	       , apply dfs again to find the new d_max, this is the final diameter of the tree.	
*/
/*	Author
@ Pranjal Walia
IIIT Bangalore
*/

#include<bits/stdc++.h>
using namespace std;

void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

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
#define mem(a,x,n)					memset(a,x,sizeof(a))		//initialise only 0 ans -1 with memset
#define ps(x,y)         				fixed<<setprecision(y)<<x
#define mk(arr,n,type)  				type *arr=new type[n];
#define w(x)            				int x; cin>>x; while(x--)
#define sortv(v)        				sort(v.begin() , v.end())
#define rsortv(v)       				sort(v.rbegin() , v.rend())
#define pw(b,p)         				pow(b,p) + 0.1
#define __          	   				ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,a,b)	   					for(int i=a;i<b;i++)
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
            res = res * a;
        a = a * a;
        b >>= 1;
    }
}

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

const int N = 1e5+5;
vi g[N];
int vis[N];

int cc_size;

void dfs(int node){
    vis[node]=1;
    cc_size++;
    for(int child : g[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

void FIRESC(){
w(t){
        int ans1=0;
        int ans2=1;

        FOR(i ,0 , N){
        g[i].clear();
        vis[i]=0;
        }

        int n,e;sd2(n,e);
        FOR(i ,0 ,e){
            int u,v;
            sd2(u,v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }

        FOR(i ,0 , n){
            if(!vis[i]){
                cc_size=0;
                dfs(i); ans1++;
                ans2 = (ans2*(cc_size))%mod;
            }
        }

        tr2(ans1,ans2);
    }
}


int d_max;
int max_node;

void dfs_d(int node , int d){
    vis[node] = 1;
    if(d > d_max){
        d_max = d;
        max_node = node;
    }
    for(int child : g[node]){
        if(!vis[child]){
            dfs_d(child , d+1);
        }
    }
}

void brute_diameter(){
file();
    int n,e; sd2(n,e);
    FOR(i ,0 , e){
        int u,v; sd2(u,v);
        g[v].pb(u);
        g[u].pb(v);
    }
    for(int i=1; i<n+1 ; i++){
        dfs_d(i ,0);
        cout << d_max << endl;
    }
}

int32_t main(){
    __;
    // file();
    int n;sd(n);
    FOR(i ,0 ,n-1){
        int u,v; sd2(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    d_max = -1;
    dfs_d(1,0);

    /*  
        VERY IMPORTANT --> THE STEPS I FORGET WHEN CHANGING THE ROOT
        1. reset the visited array
        2. clear the value of the max_d !! important
    */

    FOR(i ,1 , n+1) vis[i]=0;
    d_max = -1; 
    
    dfs_d(max_node , 0);
    tr(d_max);
    return 0;
}
