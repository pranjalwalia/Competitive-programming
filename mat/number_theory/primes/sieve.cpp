#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;
bool isprime[N];

void sieve(){
    int maxn = N-1;
    for(int i=1 ; i<= maxn ; i++) isprime[i] = 1;
    isprime[0] = isprime[1] = 0;

    for(int i=2 ; i*i<=(maxn) ; i++){
        if(isprime[i]){
            for(int j=i*i;  j<= maxn ; j+=i)
                isprime[j]=0;
        }
    }
}

int main(){
    int n = 5;
    sieve();
    cout << isprime[n] << endl;
}
