#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	int ans = a/b;
	if(a%b)  
		ans++;
	cout<<ans;
	return 0;
}