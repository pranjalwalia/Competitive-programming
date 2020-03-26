#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s = "";
        int n;
        long long int k;
        cin >> n >> k;
        long long int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        long long int x = k;
        // s+='a';
        // cout << s;

        for(int i=0 ; i<n ; i++){
            if(x >= a[i]){
                x = x-a[i];
                s+='1';
            }
            else{
                s+='0';
                continue;
            }
        }
            cout << s << endl;
    }
}
