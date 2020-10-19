#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll func(ll h){
	if(h==1)
		return 1;
	return 1+2*func(h/2);
}

int main(){
	ll h;
	cin>>h;
	cout<<func(h);
	return 0;
}