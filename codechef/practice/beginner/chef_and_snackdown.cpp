#include<bits/stdc++.h>
using namespace std;

int main(){
    //2010, 2015, 2016, 2017 and 2019.

    int t;
    cin >> t;
    while(t--){
        int x;
        cin >>x;
        if( x==2010 || x == 2015 || x==2016 || x==2017 || x==2019 ){
            cout << "HOSTED" << endl;
        }
        else{
            cout << "NOT HOSTED" << endl;
        }
    }
}
