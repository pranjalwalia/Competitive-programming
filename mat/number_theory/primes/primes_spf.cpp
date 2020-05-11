#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define ii              pair<int,int>
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

void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

void file(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}

const int N = 1e6+7;
int spf[N];

void sof(){
	spf[1] = 0;
	for(int i=2 ; i<N ; i++)
		spf[i]=i;
	for(int i=4; i<=N ; i+=2)
		spf[i]=2;

	for(int i=3 ;i*i <= N ; i++){
		if(spf[i]==i){
			for(int j=i*i ; j<N ; j+=i){
				if(spf[j]==j){
					spf[j] = i;
				}
			}
		}
	}
}


int32_t main(){	
	__;
	sof();
	rep(i, 1 , 50){
		if(spf[i]==i)
			cout << i << " " << " prime" << endl;
		else cout << i << " " << "not prime" << endl;
	}
}
