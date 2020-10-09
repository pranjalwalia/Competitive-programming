#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,n,sum,y;
	cin>>x>>n;
	sum = 0;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>y;
		sum+=y;
	}
	if(sum>=x)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}