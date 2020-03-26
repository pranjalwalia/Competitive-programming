#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pb push_back
#define InpArr(a,n) for(ll i=0; i<n ; i++){cin >> a[i];}
#define PrintArr(a,i,j) for(ll k=i ; k<=j ; k++){cout << a[k] << " ";} 
#define lcm(a,b) (a*b)/__gcd(a,b)
#define ump unordered_map<ll,ll>ump;
#define loop(i,x,y) for(ll i=x;i<y;i++)
#define rloop(i,x,y) for(ll i=x-1;i>=y;i--)

int func(int a[] , int n){
	int c=0;
	for(int i=0 ; i<n ; i++){
		if(a[i] >0){
			c++;
		}
	}
	return c;
}

int mymin(int a[] , int n){
	int m=numeric_limits<int>::max();
	for(int i=0 ; i<n ; i++){
		if(a[i] < m && a[i]>0){
			m = a[i];
		}
	}
	return m;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	InpArr(a,n);
	sort(a,a+n);
	cout << func(a,n) << "\n";
	while(func(a,n) > 0){
		int m = mymin(a,n);
		for(int i=0 ; i<n ; i++){a[i]-=m;}
		if(func(a,n)==0){break;}
		cout << func(a,n) << "\n";
	}

}
