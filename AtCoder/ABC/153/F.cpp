#include<bits/stdc++.h>
using namespace std;

int main(){
	ll n,d,a,y,z;
	cin>>n>>d>>a;
	vector<ll> x(n);
	vector<pair<ll,ll>> v(n);
	for(int i=0;i<n;i++){
		cin>>y;
		cin>>z;
		v[i]={y,z};
	}
	sort(v.begin(), v.end());
	vector<ll> times(n);
	for(int i=0;i<n;i++){
		x[i] = v[i].fi;
		times[i] = (v[i].se+a-1)/a;
	}
	vector<ll> far(n,0);
	for(int i=0;i<n;i++){
		far[i] = upper_bound(x.begin(), x.end(), x[i]+2*d) - x.begin();
	}

	ll ans = 0;
	vector<ll> damage(n+2,0);
	for(int i=0;i<n;i++){
		if(!i){
			damage[i]=times[i];
			ans+=times[i];
			damage[far[i]]-=times[i];
		} else {
			damage[i]+=damage[i-1];
			if(times[i]<=damage[i]){
				continue;
			} else {
				ll temp=times[i]-damage[i];
				damage[i]+=temp;
				ans+=temp;
				damage[far[i]]-=temp; 
			}
		}
	}
	cout<<ans;
	return 0;
}