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

int fib_itr(int x){				//all required values are computed only once
	int f1=0;					// O(n)
	int f2=1;
	int f;

	for(int i=2 ; i<=x ; i++){
		f = f1+f2;
		f1 = f2;
		f2 = f;
	}
	return f;
}

int fib(int x){					//slower -- as many values are computed many times
	
	if( x <=1 )
		return x;				// O(2^n)

	return fib(x-1)+fib(x-2);
}


int F[51];								// constraint -- our upper bound now has become n==51
										//global array ( stays the same during recursive calls ) to store percalculated values of fib(i)
int fib_memoization(int n){
	if(n<=1)
		return n;

	if(F[n] != -1)
		return F[n];

	F[n] = fib_memoization(n-1) + fib_memoization(n-2);
	return F[n];
}


int32_t main(){	
	//file();
	for(int i=0 ; i<51 ; i++)
		F[i] = -1;

	int n; cin>>n;
//	cout << fib_itr(n) << endl;
//	cout << fib(n) << endl;
//	cout << fib_memoization(n) << endl;



}
