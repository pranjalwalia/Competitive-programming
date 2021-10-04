#include<bits/stdc++.h>
using namespace std;

void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

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
#define __          	   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b)	   for(int i=a;i<b;i++)
#define repb(i,a,b) 	   for(int i=a;i>=b;i--)
#define endl			   "\n"    

void file(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

int32_t main(){
    __;	
    int t;
    int tc=0;
    cin >> t;
    while(t--){
        tc++;
        string s;
    cin >> s;
    int n = s.length();

    string ans = "";
    vi v;
    vi d;
    rep(i , 0, s.length()){
        v.pb(s[i]-'0');
    }
    for(int i=0 ; i<n-1 ; i++){
        d.pb(v[i+1]-v[i]);
    }
    int j=0;
    while(j < v[0]){
        ans+=('(');
        j++;
    }
    ans+=s[0];
    for(int i=1 ; i<n ; i++){
        if(d[i-1]==0){
            ans+=s[i];
        }
        else if(d[i-1]>0){
            int k = d[i-1];
            while(k>0){
                ans+='(';
                k--;
            }
            ans+=s[i];
        }
        else if(d[i-1]<0){
            int k = d[i-1];
            while(k < 0){
                ans+=')';
                k++;
            }
            ans+=s[i];
        }
    }

    int x=v[n-1];
    for(int i=0 ; i<v[n-1] ; i++){
        ans+=')';
    }
    cout << "Case #" << tc <<  ": " << ans << endl;
    }
}
