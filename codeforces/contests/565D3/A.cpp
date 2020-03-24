#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define endl            "\n"

void file(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

int check(int n){
    if(n%2!=0 && n%3!=0 && n%5!=0){
        return 1;
    }
    else return 0;
}

int solve(int n){
    int c=0;
    while(n > 1){
        if(check(n))
            return -1;

        else{
            if(n%2==0){
                c++;
                n/=2;
            }
            if(n%3==0){
                c++;
                n= (2*n)/3;
            }
            if(n%5==0){
                c++;
                n=  (4*n)/5;
            }
        }
    }
    return c;
}

int32_t main(){    
    //file();
    w(t){
        int n; cin >> n;
        cout << solve(n) << endl;
    }

}
