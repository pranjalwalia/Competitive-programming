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
        //TLE
        // ll n;cin>>n;
        // vi nums(n);
        // vvi twoD(300000);
        // vi gaps(n);
        // for(ll i=0;i<n;i++){
        //     cin>>nums[i];
        //     if(twoD[nums[i]].size()==0){
        //         twoD[nums[i]].push_back(-1);
        //     }
        //     twoD[nums[i]].push_back(i);
        //     gaps[i]=-1;
        // }
        // for(ll i=0;i<300000;i++){
        //     if(twoD[i].size()>0){
        //         twoD[i].push_back(n);
        //     }
        // }
        // for(ll i=0;i<300000;i++){
        //     if(twoD[i].size()>0){
        //         ll maxGap=-1*INF;
        //         for(ll j=1;j<twoD[i].size();j++){
        //             if(twoD[i][j]-twoD[i][j-1]>maxGap){
        //                 maxGap=twoD[i][j]-twoD[i][j-1];
        //             }
        //         }
        //         ll temp=maxGap-1;
        //         while(gaps[temp]==-1 and temp<n){
        //             gaps[temp++]=i;
        //         }
        //     }
        // }
        // for(int num:gaps){
        //     cout<<num<<" ";
        // }
        // cout<<endl;
        ll n;cin>>n;
        vi nums(n);
        vi gaps(n);
        map<int,vi>hashT;
        for(ll i=0;i<n;i++){
            cin>>nums[i];
            hashT[nums[i]].push_back(i);
            gaps[i]=-1;
        }
        map<int,vi>::iterator itr;
        
        for(itr=hashT.begin();itr!=hashT.end();itr++){
            ll maxGap=(itr->second)[0]+1;
            ll i;
            for(i=1;i<(itr->second).size();i++){
                if((itr->second)[i]-itr->second[i-1]>maxGap){
                    maxGap=(itr->second)[i]-itr->second[i-1];
                }
            }
            if(n-(itr->second)[i-1]>maxGap){
                maxGap=n-(itr->second)[i-1];
            }
            if(gaps[maxGap-1]==-1 or gaps[maxGap-1]>(itr->first)){
                gaps[maxGap-1]=itr->first;
            }
        }
        ll i=0;
        while(i<gaps.size() and gaps[i]==-1){
            i++;
        }
        if(i<gaps.size()){
            ll temp=gaps[i++];
            while(i<gaps.size()){
                while(i<gaps.size() and gaps[i]==-1){
                    gaps[i++]=temp;
                }
                if(i<gaps.size()){
                     if(gaps[i]<temp){
                        temp=gaps[i++];
                    }
                    else{
                        gaps[i++]=temp;
                    }
                }
            }
        }
        for(int num:gaps){
            cout<<num<<" ";
        }
        cout<<endl;
    }
	//cout<<(double)(clock()-tStart)/CLOCKS_PER_SEC;
	return 0;
}