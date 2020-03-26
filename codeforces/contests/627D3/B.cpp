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


int32_t main(){	
	 file();

	w(x){
		int n; cin >> n;
		mk(a,n,int);
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
		}
        map<int,vi>m;

        for(int i=0 ; i<n; i++){
            m[a[i]].pb(i);
        }
        int flag=0;
        
        //check for palindromes of size 3;

        //if palindrome of form x x x 
        for(auto itr : m){
            if(itr.ss.size() >= 3){
                flag =1;
                break;
            }
        }


        //if palindrome of form x y x -- both the x shouldnt be adjacent
        for(auto itr: m){
            if(itr.ss.size()==2 && itr.ss[0]+1 != itr.ss[1]){
                flag = 1;
                break;
            }
        }
        
        if(flag == 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
	}
}