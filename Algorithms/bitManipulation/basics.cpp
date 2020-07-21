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
/*
	WARNING! always use 0 based indexing in bit manipulations...

*/

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


bool check_power_of_two(int n)
{
	if(n<=0) return 0;
	// return (ceil(log2(n)) == floor(log2(n))); => slow..
	if(n&(n-1) == 0) return true;
	else return false;
}

void unique_in_vector(){
	//find the unique element in the vector..
	vi v = {5,15,5,3,5,15}; int x=v[0];
	rep(i ,0,v.size()){	
		x^=v[i];
	}
	tr(x);
}

void find_duplicate(){
	vi v = { 23 , 21 , 24 , 27 , 22 , 27 , 26 , 25 };
	/*
		Algo: use the facts that n^n=0 and n^0=n.

		1. find the min and max in the array => O(N).
		2. find the xor of all integers in range [min,max] => x = min^(min+1)^....^(max).
		3. find the xor of all elements in the array => y = a[0]^a[1]^a[2]...^a[n-1].
		4. ans = x^y;
	*/    
}

void odd_or_even(int n){
	//check odd and even..
	//(n&1) => odd
	//(!(n&1)) => even
	//((n&1)^1) => even
}

void count_set_bit(int n){	//better way is to use bitset..
	//dry run this..count the number of set bits in a number..
	int count=0;
	while(n>0){
		if(n&1){
			count++;
		}
		n>>1;
	}
}

int count_set_alternate(int n){
	// n&(n-1) => drops the last set bit (lsb)..
	// eg: 14(1110) => 12(1100)
	int count=0;
	while(n>0){
		// in each cycle, the lsb is dropped...
		count++;
		n = (n&(n-1));
	}
	return count;
}

bool check_jth(int n , int x){	//check if the jth bit from the right is set or not...
	return (n&(1<<(x)));
	/*
	// 42 = 1 0 1 0 1 0 
	rep(i ,0 ,6)
	cout << check_jth(42,i) << endl;
	*/
	// remember the rightmost bit is treated as the zeroth bit..
}

int set_jth(int x , int j){
	//turn on the jth bit..
	return (x|(1<<(j-1)));
}

int unset_jth(int x , int j){
	return (x & ~(1<<(j-1)));
}

int flip_jth(int x ,int j){
	return (x^(1<<(j-1)));
}

int lsb(int x){
	// lsb => right most set bit..
	//comparing the binary rep of x and -x, only the lsb is same for the 2...nothing else..
	int k = (x & (-x));
	//returns the index (0-based)
	return log2(k); 
}

int32_t main(){	
	__;
	file();
	return 0;
}

