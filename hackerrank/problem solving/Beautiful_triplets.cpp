#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pb push_back
#define InpArr(a,n) for(ll i=0; i<n ; i++){cin >> a[i];}
#define PrintArr(a,i,j) for(ll k=i ; k<=j ; k++){cout << a[k] << " ";} 
#define lcm(a,b) (a*b)/__gcd(a,b)
#define ump unordered_map<ll,ll>ump;
#define loop(i,x,y) for(ll i=x;i<y;i++)
#define rloop(i,x,y) for(ll i=x-1;i>=y;i--)

using namespace std;

int main(){
    int n,d;
    cin >> n >> d;
    int a[n];
    InpArr(a,n);
    int count=0;
    
    for(int i=0; i<n ; i++){
        bool b1 = binary_search(a+i,a+n,a[i]+d);
        bool b2 = binary_search(a+i,a+n,a[i]+2*d);
        if(b1 && b2){
            count++;
        }
    }

    cout << count << endl;

   
}
