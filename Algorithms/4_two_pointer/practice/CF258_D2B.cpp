#include<bits/stdc++.h>
using namespace std;

/*
  Given an array that is not sorted, is it possible to find and reverse a subarray so that the resulting array is sorted?
  If yes, indicate the index of the end points of the array..
*/

int32_t main(){	
	__;
	file();
	int n; sd(n); int a[n]; int b[n]; rep(i,0,n) sd(a[i]); rep(i,0,n) b[i]=a[i]; sort(b,b+n);
	int s=0; int e=0;
	for(int i=0 ; i<n ; i++){
		if(a[i] != b[i]){
			s=i; break;
		}
	}
	for(int i=n-1 ; i>=e ; i--){
		if(a[i] != b[i]){
			e=i; break;
		}
	}
	int f=0;
	for(int i=s,j=e ; i<=e and j>=s ; j--,i++){
		if(a[j] != b[i])
		{
			f=1; cout << "no" << endl; break;
		}
	}
	if(!f){
		cout << "yes" << endl;
		cout << s+1 <<" " << e+1 << endl;
	}
	return 0;
}




