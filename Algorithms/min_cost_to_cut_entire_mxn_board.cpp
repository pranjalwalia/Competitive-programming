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

/*
	find the minimum cost to cut the entire board of 
	m*n dimensions into squares..

	1. sort the cut costs along x and y
	2. select the max greedily
	3. keep incrementing the number of horizontal and vertical components..
	4. for a vertical cut --> max vertical_cost * #(horizontal components)
	5. for a horizontal cut --> max horizontal_cost * #(vertical components)
	6. if vertical cuts get finished first, cut the remaining portions in the horizontal..
	7. component of the above step..
	
  //https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/
  // spoj => chocoloa
  
1
6 4
2
1
3
1
4
4
1
2

42
*/

bool cmp(int x , int y){
	return x>y;
}

int32_t main(){	
	__;
	file();
	w(t){
		int m,n; sd2(m,n);
		int x[m-1];
		int y[n-1];
		rep(k ,0 ,m-1) sd(x[k]);
		rep(k ,0, n-1) sd(y[k]);
		sort(x , x+m-1 , cmp);
		sort(y , y+n-1 , cmp);
		int v=1; int h=1;
		int ans=0;
		int i=0 , j=0;

		while(i < m-1 and j<n-1){
			if(x[i] > y[j]){
				ans+=(v*x[i++]);
				h++;
			}
			else{
				ans+=(h*y[j++]);
				v++;
			}
		}
		while(i<m-1){
			ans+=(x[i++]*v);
		}
		while(j<n-1){
			ans+=(y[j++]*h);
		}
		tr(ans);
	}
	return 0;
}




