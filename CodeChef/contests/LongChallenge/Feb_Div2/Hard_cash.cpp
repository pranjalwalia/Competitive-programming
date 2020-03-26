#include<bits/stdc++.h>
using namespace std;

long long int maxi(long long int a[] , long long int n){
    long long int m = a[0];
    for(long long int i=0 ; i<n ; i++){
        if(m < a[i]){m = a[i];}
    }
    return m;
}

long long int lin(long long int a[] , long long int n , long long int x){
    for(long long int i=0 ; i<n ; i++){
        if(a[i] == x){
            return i;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n,k;
    cin >> n >> k;
    long long int a[n];
    for(long long int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    long long int m = maxi(a,n);
    long long int index = lin(a,n,m);
    
    long long int s=0;

    for(long long int i=0 ; i<=index ; i++){
        if(a[i]%k!=0){
            s+=(a[i]%k);
        }
    }

    long long int s1=0;
    for(long long int i=index+1 ; i<n ; i++){
        s1+=a[i];
    }
    long long int r = (s1+s)%k;
    cout << r << endl;

    }   
}
