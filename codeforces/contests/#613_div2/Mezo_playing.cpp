#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 0;
    int l;
    cin>>l;
    string s;
    cin >> s;
    int c2=0;
    int c1=0;
    for(int i=0 ; s[i] ; i++){
        if(s[i] == 'L'){
            c1++;
        }
        else if(s[i] == 'R'){
            c2++;
        }
    }
    cout << c1 + c2 + 1 << endl;
}
