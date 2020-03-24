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

void file(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

int32_t main(){    
    //file();
    w(t){
        int n;
        cin >> n;
        mk(a,n,int);
        mk(count,3,int);
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            ++count[a[i]%3];
        }
        int ans = count[0];
        int lb = min(count[1] , count[2]);
        ans+=lb;
        count[1]-=lb;
        count[2]-=lb;
        if(count[1])
            ans+=count[1]/3;
        else ans+=count[2]/3;

        cout << ans << endl;
    }

}
