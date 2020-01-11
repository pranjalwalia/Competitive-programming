#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n ;i++){
            cin >> a[i];
        }
        int gcd = __gcd(a[0] , a[1]);
        for(int i=0 ;i<n ;i++){
            if(gcd==1){
                break;
            }
            else{
                gcd = __gcd(gcd,a[i]);
            }
        }
        for(int i=2;i<n ;i++){
            cout << a[i]/gcd << " ";
        }

    }
}
