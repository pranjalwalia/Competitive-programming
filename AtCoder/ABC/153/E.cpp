#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

vector<ll> a,b;
vector<vector<ll>> dp;

ll func(ll idx, int health){
	if(health<=0)
		return 0;
	if(idx==-1)
		return INF;
	if(dp[idx][health]!=-1)
		return dp[idx][health];
	return dp[idx][health] = min(b[idx]+func(idx, health-a[idx]), func(idx-1,health));
}

int main()
{
	ll h,n;
	cin>>h>>n;
	a.resize(n);
	b.resize(n);
	dp.resize(n+1, vector<ll> (h+1,-1));
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	cout<<func(n-1, h);
	return 0;
}