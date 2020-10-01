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
    //Testcase missing
    //reason:not changing the output back to non sorted input
    // ll t;cin>>t;
    // while(t--){
        // ll n,t;cin>>n>>t;
        // vl nums(n);
        // vector<bool>ans(n);
        // for(ll i=0;i<n;i++){
        //     cin>>nums[i];
        // }
        // sort(nums.begin(),nums.end());
        // ll p1=0,p2=n-1;
        // while(nums[p2]>t){
        //     ans[p2]=1;
        //     p2--;
        // }
        // while(p1<p2){
        //     if(nums[p1]+nums[p2]==t){
        //         ans[p1++]=0;
        //         ans[p2--]=1;
        //     }
        //     else if(nums[p1]+nums[p2]<t){
        //         ans[p1++]=0;
        //     }
        //     else{
        //         ans[p2--]=1;
        //     }
        // }
        // if(p1==p2){
        //     if(binary_search(nums.begin(),nums.begin()+p1,t-nums[p1])){
        //         ans[p1]=1;
        //     }
        //     else{
        //         ans[p1]=0;
        //     }
        // }
        // for(ll i=0;i<n;i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
    ll t;cin>>t;
    while(t--){
        ll n,T;cin>>n>>T;
        vi nums(n);
        for(ll i=0;i<n;i++){
            cin>>nums[i];
        }
        map<ll,ll>bag1,bag2;
        ll i=0;
        vi sol;
        while(i<n){
            if(bag1.find(T-nums[i])==bag1.end()){
                bag1[nums[i]]=1;
                sol.push_back(0);
            }
            else if(bag2.find(T-nums[i])==bag2.end()){
                bag2[nums[i]]=1;
                sol.push_back(1);
            }
            else{
                if(bag1[T-nums[i]]<bag2[T-nums[i]]){
                    bag1[nums[i]]++;
                    sol.push_back(0);
                }
                else{
                    bag2[nums[i]]++;
                    sol.push_back(1);
                }
            }
            i++;
        }
        for(int num:sol){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    //cout<<(double)(clock()-tStart)/CLOCKS_PER_SEC;
    return 0;
}