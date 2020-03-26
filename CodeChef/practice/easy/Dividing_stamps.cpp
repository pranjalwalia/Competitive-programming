#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    int sum=0;
    for(int i=0 ; i<n ; i++){
        sum+=a[i];
    }
    if(sum == n*(n+1)/2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
