#include<bits/stdc++.h>
using namespace std;


int phi_sqrt(int n){
	//as we get the factorisation in O(sqrt(N))
	int res = n;
	for(int i=2 ; i*i <= n ; ++i){
		if(n%i==0){
			res/=i;
			res*=(i-1);

			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>1){
		res/=n; res*=(n-1);
	}
	return res;
}


const int N = 1e6+5;
int phi[N];
void init(){
	for(int i=1 ; i<=N ; ++i) phi[i]=i;

	for(int i=2 ; i<=N ; ++i){
		if(phi[i]==i){
			for(int j=i; j<=N; j+=i){
				phi[j]/=i;
				phi[j] *= (i-1);
			}
		}
	}
	//similar to the spf sieve..
}


int main(){
	//phi(N) gives the #(natural numbers) upto N that are co-prme to N,
	//i.e gcd(i,N)==1.
	
	//bruteForce// run a loop from 1 to N and ++cnt if gcd==1 => O(NlogN)
	// phi(prime) == prime-1	=> important observation as every single number upto prime is co-prime with p
	/*
	 *	how to calculate phi(p^x) where p is a prime and x>=1
	 *	phi(p^x) = #(coprimes) upto p => p^x - #(multiples upto p^x)
	 *				      => p^x - (p^x)/p
	 *			 phi(p^x)     => p^x - p^(x-1) => (p^(x-1)) * (p-1);
	 *
	 *	Now we have to generalise this for a number N.
	 *	1. Etf is a multiplicative function i,e f(NxM) = f(N)Xf(M), where N and M are co-prime.
	 *	2. get the prime factorisation of N => N = p1^(x1) * p2^(x2) * p3^(x3) .....=> f(N) = f(p1^x1) * f(p2^x2).....because all prime powers are co-prime to each other.
	 *	3. #(divisors) = (x1+1)(x2+1)... => also a multiplicative function
	 *	4. Now phi(P[i]^x[i]) = PI(p[i]^(x[i]-1)*(p[i]-1)) , PI => product on all prime factors of N
	 *	5. phi(N) = (p1^(x1-1) * p2^(x2-1) ....) (p1-1)(p2-1)(p3-1)...=> multiply and divide by p1 p2 p3..
	 *	6. phi(N) = N * (p1-1)/p1 * (p2-1)/p2 * (p3-1)/p3 * (p4-1)/p4.....
	 *
	 */
	cout << phi_sqrt(200) << endl;	//should give 80..
	
	/*
	 *  Calculating the totient function in O(Nlog(logN))
	 *
	 */
	init();
	cout << phi[200] << endl;	//80
	cout << phi[173] << endl;	//172
	cout << phi[5] << endl;		//4
	
	return 0;
}


