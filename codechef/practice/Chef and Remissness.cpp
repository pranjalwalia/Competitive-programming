#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll max(ll x , ll y){
    if(x>=y){
        return x;
    }
    else{
        return y;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x,y;
    cin >> x >> y;
    cout << max(x,y) << " " << x+y << endl;
    }
    
}
