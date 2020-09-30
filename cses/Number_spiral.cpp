#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define RREP(i,a,b) for (int i = a;i<b;i++)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define ull unsigned long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ull y,x;
    int t;
    cin>>t;
    while(t--){
        cin>>y>>x;
        if(y>x){ // y is greater
            if(y%2==0){ //if y is even
                cout<<(y*y)-x+1<<endl;
            }
            else{
                cout<<(y-1)*(y-1)+x<<endl;
            }
        }
        else{ // x is greater or equal
            if(x%2==1){ // x is odd
                cout<<x*x-y+1<<endl;
            }
            else{
                cout<<(x-1)*(x-1)+y<<endl;
            }
        }
    }

    return 0;
}