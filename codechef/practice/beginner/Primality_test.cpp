#include<bits/stdc++.h>
using namespace std;

int prime(int n){
    for(int i=2; i<=sqrt(n) ; i++){
        if(n%i==0){
            return 0;
        }
        else{
            continue;
        }
    }
    return 1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(prime(n)==1){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}
