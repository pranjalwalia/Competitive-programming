#include<bits/stdc++.h>
using namespace std;

int maxima(int a[] , int n){
    int max = a[0];
    for(int i=0 ; i<n ; i++){
        if(a[i] > max ){
            max = a[i];
        }
    }
    return max;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        int max = maxima(a,n);
        int count=0;
        int count1=0;
    
        for(int i=0 ; i<n ; i++){
            count+=( max - a[i] );
            if( a[i] == max ){
                count1++;
            }
        }
    
    cout << count << " " << n - count1 +1 << endl;

    }
}
