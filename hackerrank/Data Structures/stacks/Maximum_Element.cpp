#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int>s;
    int n,x;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        int q;
        cin >> q;
        switch(q){
            case 1:
                cin >> x;
                if(s.empty()){
                    s.push(x);
                }
                else{
                    s.push(max(x,s.top()));
                }
                break;
            case 2:
                if(!s.empty()){
                    s.pop();
                }
                break;
            case 3:
                cout << s.top() << endl;
                break;
            default:
                break;
        }
    }
}
