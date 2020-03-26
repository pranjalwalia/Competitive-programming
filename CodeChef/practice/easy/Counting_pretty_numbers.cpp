#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){
        long long int L,R;
        cin >> L >> R;
        int count=0;
        for(long long int i=L ; i<=R ; i++){
            int y = i%10;
            if(y==2 || y==3 || y==9){
                count++;
            }
        }

        cout << count << endl;
    }
}
