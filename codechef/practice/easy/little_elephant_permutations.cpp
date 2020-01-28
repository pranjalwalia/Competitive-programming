#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++){cin >> a[i];}
        int count1=0;
        int count2=0;

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(a[i]>a[j]){
                    count1++;
                }
            }
        }

        for(int i=0 ; i<n-1 ; i++){
            if(a[i] > a[i+1]){
                count2++;
            }
        }

        if(count1==count2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }

}
