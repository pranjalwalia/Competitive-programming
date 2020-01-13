#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
    cin >> s;
    int n,m;
    cin >> n >> m;
    vector<char>v;
    for(int i=0 ;i<s.length() ; i++){
        if(i>=n && i<=m){
            v.push_back(s[i]);
        }
    }
    sort(v.begin(), v.end());
    string s1 = "";
    for(int i=v.size()-1 ; i>=0 ; i--){
        s1+=v[i];
    }
    
    
    for(int i=0 ; i<n ; i++){
        cout << s[i];
    }
    cout << s1;
    for(int i=m+1 ; i<s.length() ; i++){
        cout << s[i];
    }
    }
    
}
