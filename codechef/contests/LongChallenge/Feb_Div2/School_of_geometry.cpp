#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
    long long int n;
    cin >> n;
    long long int a[n];
    long long int b[n];
    for(long long int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    for(long long int i=0 ; i<n ; i++){
        cin >> b[i];
    }

    long long int s=0;
    sort(a,a+n);
    sort(b,b+n);

    for(long long int i=0 ; i<n ; i++){
        s = s + min(a[i] , b[i]);
    }

    cout << s << endl;
    }
    
}
