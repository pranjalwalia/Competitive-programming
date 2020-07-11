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


/*
	Epic Combinatorics going on here...

	I know it's an old post, but the solution for B can be done in O (1) time using maths:

Finding k_max: 
-The formula for finding the number of distinct pairs in a list of numbers goes like this: n * (n - 1) / 2 - where n is the length of the list. 
If we expand it, we get a quadratic equation: (n ^ 2 - n) / 2. 
Quadratic equations grow exponentially, thus we can say that if we want the highest k_max, we want to make 1 team have as many participants as possible .
 We can do this by giving every team only 1 participant: 1 * (1 - 1) / 2 = 0, and all the remaining participants go to any 1 team, making the k_max as large as it can be. 
 Final formula: (n - m + 1) * (n - m) / 2 - here we replace the original n with n - m + 1, which equates to taking away m - 1 participants for every team except 1, and if we subtract the amount of participants taken with the number of participants, we get: n - (m - 1) = n - m + 1, thus the formula returns k_max.



Finding k_min: -As we said in the previous example, the formula for finding the amount of distinct pairs in a list of numbers is quadratic, the lower number of participants in each team, lower k_min. Instead of bunching every single possible participant into 1 team, we now want to spread the participants as much as possible, so that we get the lowest possible k_min. 
Final formula: n / m * (n / m - 1) / 2 * (m - n% m) + (n / m + 1) * n / m / 2 * (n% m). 
This one is a bit more complicated so we will take it apart and analyze it bit by a bit. 
First off, let's see what n / m * (n / m - 1) / 2 * (m - n% m) does. In the formula '/' is floor division and '%' is modulus. If we replace n / m with n, we can see the resemblance to the original formula: n * (n - 1) / 2 * (m - n% m). 
We replace n with n / m, because n / m returns the amount of participants in each team if we spread them out as much as we can (it will miss out on a few participants which are extra, since it's floor division). 
This way we can calculate how many participants each team has. In the part of the formula, we also see (m - n% m) multiplier. 
The multiplier has 2 parts: m and n% m, m returns the number of teams, and n% m returns the number of participants who are extra. 
With the 1st part of the Final formula (which is n / m * (n / m - 1) / 2), we can see that we calculate the number of participants each team has, we want to multiply it by the number of teams m, but we only want to multiply it with teams which don't have the extra participant, so we subtract m with n% m -> m - n% m. 
The second part of the final formula goes like this: (n / m + 1) * n / m / 2 * (n% m). Firstly let's analyze (n / m + 1) * n / m / 2, here we can see that n from the original formula is replaced with n / m + 1. 
That's because we are also trying to see how many participants each team has with n / m, but we're also counting the extra participant so we add 1 -> n / m + 1. If we replace n / m + 1 with n, we get: n * (n - 1) / 2 * (n% m). 
The n% m part is the last piece of the puzzle. We multiply the amount of participants each team has (counting the extra participant) with n% m, because that returns the amount of extra participants, so each extra participant we add to a team to spread them out as much as possible. s because we are also trying to see how many participants each team has with n / m, but we're also counting the extra participant so we add 1 -> n / m + 1. 
If we replace n / m + 1 with n , we get: n * (n - 1) / 2 * (n% m). The n% m part is the last piece of the puzzle. We multiply the amount of participants each team has (counting the extra participant) with n% m, because that returns the amount of extra participants, so each extra participant we add to a team to spread them out as much as possible. s because we are also trying to see how many participants each team has with n / m, but we're also counting the extra participant so we add 1 -> n / m + 1.
 If we replace n / m + 1 with n , we get: n * (n - 1) / 2 * (n% m). The n% m part is the last piece of the puzzle. We multiply the amount of participants each team has (counting the extra participant) with n% m, because that returns the amount of extra participants, so each extra participant we add to a team to spread them out as much as possible.


where '/' is floor division and '%' is modulus.
*/

int32_t main(){	
	__;
	file();
	int n,m; sd2(n,m); int kmax=0,kmin=0;
	int tmax = n-m+1;
	kmax=(tmax*(tmax-1))/2;				// (n-m+1)C2
	int p=(n/m);
	kmin = ( ((p*(p-1))/2)*(m-n%m) + ((p*(p+1))/2)*(n%m) );
	tr2(kmin , kmax);
	return 0;
}




