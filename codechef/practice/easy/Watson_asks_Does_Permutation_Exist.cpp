#include<bits/stdc++.h>
using namespace std;

int func(long long int a[] , int n){
    int flag=1;
    for(int i=0 ; i<n-1 ; i++){
        if(abs(a[i]-a[i+1])>1 ){
            flag = 0;
            return flag;
        }
    }
        return flag;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        
        if(func(a,n)==1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
