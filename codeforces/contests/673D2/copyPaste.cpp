#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef priority_queue<int> pqi;
typedef priority_queue<int,vi,greater<int> > pqs ;

#define SWAP(a,b)       int temp=a;a=b;b=temp;
#define MAX(a,b)        (a>b?a:b)   
#define MIN(a,b)        (a<b?a:b)
#define mp 				make_pair;
#define pb 				push_back;
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define __              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b) 		for(int i=a;i<b;i++)
#define repb(i,a,b) 	for(int i=a;i>=b;i--)
#define inp(a,n)		for(int i=0 ; i<n ; i++){cin >> a[i];} 
#define endl			"\n"
#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

void file(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}

int main(){
	//clock_t tStart=clock();
	__;
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vi nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        ll count=0;
        for(int i=1;i<n;i++){
            count+=floor((k-nums[i])/nums[0]);
        }
        cout<<count<<endl;
    }
	//cout<<(double)(clock()-tStart)/CLOCKS_PER_SEC;
	return 0;
}