#include<bits/stdc++.h>
using namespace std;


int mypow(int a, int b){	//(logn) --> faster than recursive --> binary expo
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

/*******************************************************************************/

int fast_expo(int x, unsigned int y, int p){ 
	int res = 1;	  
	x = x % p; 
	if (x == 0) return 0;                   //call fast_expo(2,5,mod)
	while (y > 0){ 
		if (y & 1) 
			res = (res*x) % p; 
		y = y>>1;							//y = y/2 
		x = (x*x) % p; 
	} 
	return res; 
} 

/*******************************************************************************/

int modInv(int a, int m){		//only works for m --> prime
	if(__gcd(a,m)){
			return fast_expo(a, m-2, m); 
	}
} 

/*******************************************************************************/

int main(){
	int a,b; cin >> a >> b;
	cout << modInv(a,b) << endl;
}
