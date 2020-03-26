#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n ; i++){cin >> a[i];}

    int count = 0;

    int k = a[0];

    for(int i=0 ; i<n ;i++){
        if(k >= a[i]){
            k = a[i];
            count++;
        }
    }

    cout << count << endl;

  }
}
