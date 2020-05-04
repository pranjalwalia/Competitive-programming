#include<bits/stdc++.h>
using namespace std;

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
#define pw(b,p)         pow(b,p) + 0.1

void file(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}

int pow1(int x , int n){	//O(n)
	if(n==0)
		return 1;
	return x*pow(x,n-1);
}

int pow2(int x , int n){	//O(logn)
	if(n==0)
		return 1;
	else if(n%2==0){
		int y = pow2(x,n/2);
		return y*y;
	}
	else 
		return x * pow2(x,n-1);
}

int mypow(int a, int b){	//(logn) --> faster
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int32_t main(){	
	int x = 5;
	int n = 3;
	cout << pow2(x,n) << endl;

}
