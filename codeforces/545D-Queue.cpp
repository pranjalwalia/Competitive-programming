#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    vector<long long int>v(n);
    for(long long int i=0 ; i<n ; i++){
        cin >> v[i];
    }
    sort(v.begin() , v.end());
    
    long long int count=1;

    int sum = v[0];

    for(long long int i=1 ; i<n ; i++){
        if(sum <= v[i]){
            sum = sum + v[i];
            count++;
        }
    }

    cout << count << endl;
}
