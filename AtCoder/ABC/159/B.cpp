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

bool check(string s){
	int l = s.length();
	int i=0;
	while(i <= l/2){
		if(s[i] != s[l-i-1])
			return false;
		i++;
	}
	return true;
}


int32_t main(){	
	//file();
	string s;
	cin >> s;
	string s1 = "";
	string s2 = "";
	int l= s.length();
	for(int i=0 ; i<(l-1)/2 ; i++)
		s1+=s[i];
	for(int i=(l+3)/2-1 ; i<l ; i++)
		s2+=s[i];

	if(check(s) && check(s1) && check(s2))
		cout << "Yes" << endl;
	else cout << "No" << endl;


}