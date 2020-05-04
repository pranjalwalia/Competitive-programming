#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a = 0, b = 0, lead = 0, win = 1;

    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        a += x;
        b += y;
        int l = abs(a - b);
        if(l > lead){
            if(a>b){
                win = 1;
            }
            else{
                win = 2;
            }
            lead = l;
        }
    }
    cout << win << " " << lead << endl;

    return 0;
}
                      
