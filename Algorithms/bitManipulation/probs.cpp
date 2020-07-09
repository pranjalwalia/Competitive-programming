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

int bs(int a[] , int s , int e, int x){
	if(s<=e){
		int m = (s+e)/2;
		if(a[m]==x)
			return m;
		else if(a[m] > x)
			return bs(a,s,m-1,x);
		else return bs(a,m+1,e,x);
	}
	return -1;
}

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

//Q1. print all the subsequences of a string...can be done using bit-masking..
/*
	for a string s of length l => # of subsequnces = 2^n. i.e from 0 to 2^n -1.
*/

void print_seq(string s , int i){
	int idx=0;
	while(i>0){
		(i&1) ? cout<<s[idx] : cout << "";
		idx++;
		i>>=1; 
	}
}

void generate(string s){
	int l = s.length();
	int range = (1<<l)-1;
	for(int i=0 ; i<=range ; i++){	//O(2^n)
		print_seq(s,i);				//O(N)
		cout << endl;
	}
	//O(2^N * N);
}
/*
int32_t main(){	
	__;
	file();
	string s = "xyz";
	generate(s);	
	return 0;
}
*/

// Q2.	Haming distance(HD)..in a bitset of a and b , if(a[i] != b[i]) HD++;
//Ques. => sum of pairwise haming distance of n integers.





//Q3. In an array, check if there is any combination of elements such that sum=k.
	// =>generate all possible combinations and check using bits..
bool checkSum(int a[] , int n , int k){
	for(int i=0 ; i<(1<<n) ; i++)
	{
		int curr=i; int sum=0; int x=0;
		//if jth bit is set, include it in the sum, else dont include it.
		while(curr>0){
			if(curr&1){
				sum+=a[x];
			}
			x++;
			curr = curr>>1;
		}
		if(sum==k) return true;
	}
	return false;
}

int32_t main(){
	__; file();
	int a[] = {3,4,1,2}; int n = sizeof(a)/sizeof(a[0]);
	int k=6;
	cout << checkSum(a,n,k) << endl;
}





