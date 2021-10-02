// CF259_D2B

a1, a2, ..., an → an, a1, a2, ..., a(n-1).
what is the minimum number of operations that she needs to sort the sequence?

#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
 
int n, a[2000], p[2000];
 
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		a[i+n] = a[i];
	}
	for(int i=1; i<2*n; i++){
		p[i] = p[i-1] + (a[i-1] > a[i]);
	}
	for(int i=0; i<n; i++){
		if(p[n-i] == p[2*n-1-i]){
			printf("%d", i);
			return 0;
		}
	}
	puts("-1");
}

// RELATION BETWEEN INVERSION COUNT FROM THE START AND FROM THE END OF THE ARRAY.???...
