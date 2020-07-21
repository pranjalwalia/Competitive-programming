/*// demo for the problem..
  https://github.com/mostafa-saad/misc/blob/master/solving-pics/codeforces/CF816B.pdf
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

//	https://codeforces.com/problemset/problem/816/B
//	excellent question for prefix sums..

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define deb3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl

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

/*
	Range update Queries in O(1)..=> rachit jain has a video on this.. if you need motivation, watch this..
	
	https://www.geeksforgeeks.org/constant-time-range-add-operation-array/
	https://www.youtube.com/watch?v=ERAHSoAk2Yo
	
	=> Have Q range update queries on an array and have to return the array at the end of Q update queries..	

	for each query [l,r] (inclusive) 
	1. a[l..r]+=x => a[l]+=x and a[r+1]-=x..
	2. At the end of queries, to return the array, 
	the ith element of the original array after a set of queries is the prefix sum till the ith index..thus
		convert the array into prefix sum array..i.e 
			for(int i=1 ; i<n ; i++) a[i] = a[i]+a[i-1];
*/

/*
	comming back to the question..
	!. for a input [x,y], all the inclusive temp are valid => range update [x,y] by x=1.
	2. reconstruct the final array..
	3. if the (final count of a node) >= k, then it is a valid node.
	4. find the number of nodes in the range [l,r] in the final queries for the answer..
*/

const int N=2e5+5;
int f[N]; 	// denotes the numebr of entries at the ith temp by the given recipes..
int valid[N];

int32_t main(){	
	__;
	file();
	int n,k,q; sd3(n,k,q);
	rep(i ,0 ,n){
		int x,y; sd2(x,y);
		f[x]+=1;
		f[y+1]-=1;
	}	
	rep(i,1,N) f[i]+=f[i-1];	//construct the final temp array after the input queries..
	rep(i ,1 ,N){
		if(f[i] >= k) valid[i]=1;
	}
	rep(i ,1 , N) valid[i]+=valid[i-1];		// to compute the number of valid arrays in range [l,r] => use prefix sum..
	while(q--){
		int l,r; sd2(l,r);
		tr(valid[r]-valid[l-1]);
	}
	return 0;
}




