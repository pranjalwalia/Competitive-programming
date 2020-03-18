#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define w(x) int x;cin>>x;while(x--)

void file(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif
}

ll solve(vector<int>v){
	int c1=0;
	int c2=0;
	for(int i=0 ; i<v.size() ; i++){
		if(v[i]%2==0)
			c1++;
		
		else c2++;
	}
	if(c1==v.size() || c2==v.size()){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
		file();
		w(x){
			int n;
			cin >> n;
			vector<int>v(n);
			for(int i=0 ; i<n ; i++)
				cin >> v[i];
			if(solve(v)==1){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
		
}
