/*	Author
@ Pranjal Walia
IIIT Bangalore
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
#define mem(a,x,n)					memset(a,x,sizeof(a))		//initialise only 0 ans -1 with memset
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
}

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}


const int N = 1e5+5;
int vis[N];
vi g[N];
stack<int>s;
/*
    A graph can have multiple order of topological sortings, but if we traverse the graph in increasing seq--> unique
    1. Maintain a global stack( different from the dfs stack ) to record the nodes after finishing their dfs traversal.
    2. After completing the dfs call to a particular node, push it onto the stack
    3. Empty the stack, the resulting order of elements is a valid topological sort.
    
    A valid topologcal sort exists for a SIMPLE directed acyclic graph.
*/
void dfs(int node){
    vis[node]=1;
    for(int child : g[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
    s.push(node);
}

// Sample DAG
// 6 6
// 5 0
// 4 0
// 5 2
// 2 3
// 3 1
// 4 1 

int32_t main(){
    __;	    
    // file();
    int n,e; sd2(n,e);
    rep(i ,0 ,e){
        int u,v; sd2(u,v);
        g[u].pb(v);         // remember graph is a DAG --> modify the adj list
    }
    rep(i , 0 , n){
        if(!vis[i])
            dfs(i);
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
