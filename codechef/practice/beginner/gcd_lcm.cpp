#include<bits/stdc++.h>
using namespace std;

// a*b = lcm(a,b) * gcd(a,b)

long long int lcm(long long int x , long long int y){
    return (x*y)/__gcd(x,y);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int x ,y;
    cin >> x >> y;
    cout << __gcd(x,y) << " " << lcm(x,y) << endl;
    }
}
