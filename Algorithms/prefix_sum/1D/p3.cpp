https://uva.onlinejudge.org/external/105/10533.pdf  => digit primes

#include<bits/stdc++.h>
using namespace std;

int mypow(int a, int b){        //(logn) fast exponentiation
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

const int N = 1e6+5;
int p[N];
bool isprime[N];

void sieve(){
	isprime[0]=0; isprime[1]=0; isprime[2]=1;
	for(int i=2; i*i<=N ; i++){
		if(isprime[i]){
			for(int j=i*i ; j<=N; j+=i){
				isprime[j]=0;
			}
		}
	}
}

int sum(int x){
	int s=0; while(x > 0){ s+=(x%10); x/=10;}
	return s;
}

int32_t main(){	
	__;
	file();
	fill(isprime , isprime+N , 1);
	sieve();
	p[1]=0; p[2]=1; p[3]=2; p[4]=2; p[5]=3;
	for(int i=6 ; i<N ; i++){
		if(isprime[i] && isprime[sum(i)])
			p[i] = p[i-1]+1;
		else p[i] = p[i-1];
	}
	int t; 
	scanf("%d" , &t);
	while(t--){
		int a,b; scanf("%d%d" , &a,&b);
		printf("%d\n" , p[a]-p[b]);
	}
	return 0;
}




