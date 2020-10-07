#include<bits/stdc++.h>
using namespace std;

int main(){

    char s[100];
    cin >> s;
    int count =0;
    int l = strlen(s);
    sort(s,s+l);
    for(int i=0 ; i<l-1 ; i++){
        if(s[i] != s[i+1]){
            count++;
        }
    }
    if(count&1){
        cout << "CHAT WITH HER!" << endl;
    }
    else{
        cout << "IGNORE HIM!" << endl;
    }

}
