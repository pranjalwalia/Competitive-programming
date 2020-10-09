#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	ll ans = 0;
	for(int i=(int)v.size()-1;i>=0;i--)
	{
		if(k){
			k--;
		}
		else{
			ans+=v[i];
		}
	}
	cout<<ans;
	return 0;
}
