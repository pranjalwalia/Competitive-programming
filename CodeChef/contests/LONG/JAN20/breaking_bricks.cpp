#include<bits/stdc++.h>
using namespace std;

int func(int a, int b , int c , int s){
    if(a+b+c <= s){
        return 1;
    }
    if( a+b <=s || b+c <=s ){
        return 2;
    }
    if( a+b > s && b+c > s ){
        return 3;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int s,a,b,c;
        cin >> s >> a >> b >> c;
    cout << func(a,b,c,s) << endl;
    }
    
    
    

}
