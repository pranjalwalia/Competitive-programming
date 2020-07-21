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
#define all(x)                          begin(x), end(x)


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

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

bool is_pal(string s) {return equal(all(s), s.rbegin());}

int mypow(int a, int b){        //(logn) --> faster than recursive --> binary expo
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
}

/*
	https://www.codechef.com/COOK118B/problems/CHEFSHIP 
*/

const int N = 1e5+7;
int h[N];
int power[N];
int p = 47;

void generate_hash(string s){
	power[0]=1;
	int l = s.length();
	for(int i=1 ; i<l ; i++){
		power[i] = ((power[i-1]%mod)*(p%mod))%mod;
	}
	for(int i=0;i<l;i++){
        h[i+1]=(h[i]*p+s[i])%mod;
    }
}

int get_hash(int l,int r){
    return  ((h[r+1]-(h[l]*power[r-l+1])%mod)+mod)%mod;
}

int32_t main(){	
	__;	
	file();
	w(t){
		string s; cin >> s;
		int f[26]; fill(f , f+26 , 0);
		rep(i ,0 ,s.length()) f[s[i]-'a']++;
		bool possible=1;
		rep(i ,0 ,26){
			if(f[i]&1){
				possible=0; break;
			}
		}
		if(!possible) cout << 0 << endl;
		else{
			generate_hash(s);
			int c=0;
			int l = s.length();

			for(int i=2 ; i<l-1 ; i+=2){
				if(get_hash(0 , i/2-1)==get_hash(i/2 ,i-1) and get_hash(i , (l+i)/2-1) == get_hash( (l+i)/2 , l-1 )){
					c++;
				}
			}
		tr(c);
		}
	}
	return 0;
}


