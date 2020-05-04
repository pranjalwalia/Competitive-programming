#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if(n==1)
        return false;
    for(int i=2 ; i<=sqrt(n) ; i++)
        if(n%i==0)return false;
    return true;
}

int main(){
    int n = 23;
    cout << isprime(n) << endl;
}