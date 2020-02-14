#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int count=0;
    while(t--){
        int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int a[3];
    a[0] = pow((x2-x1),2)+pow((y2-y1),2);
    a[1] = pow((x3-x2),2)+pow((y3-y2),2);
    a[2] = pow((x3-x1),2)+pow((y3-y1),2);
    sort(a,a+3);
    if(a[2]==a[0]+a[1]){
        count++;
    }
    }

    cout << count << endl;
    
}
