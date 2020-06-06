#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii              pair<int,int>
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
#define __              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b)         for(int i=a;i<b;i++)
#define repb(i,a,b)     for(int i=a;i>=b;i--)
#define endl            "\n"
#define m(a)            memset(a,0,sizeof(a))
#define all(x)                          begin(x), end(x)

void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

void file(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    #endif
}

int bs(int a[] , int s , int e, int x){
    if(s<=e){
        int m = (s+e)/2;
        if(a[m]==x)
            return m;
        else if(a[m] > x)
            return bs(a,s,m-1,x);
        else return bs(a,m+1,e,x);
    }
    return -1;
}

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

bool is_pal(string s) {return equal(all(s), s.rbegin());}

int mypow(int a, int b){        //(logn) fast exponentiation
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

const int N = 1e5+5;
int a[N];
int st[4*N];

int combine(int x , int y){
    return min(x,y);
}

void build(int node , int ss , int se){
    if(ss==se){
        st[node] = a[ss];
        return;
    }
    int mid = (ss+se)/2;
    build(2*node+1 , ss , mid);
    build(2*node+2 , mid+1 , se);
    st[node] = combine(st[2*node+1] , st[2*node+2]);
}

void update(int node , int ss , int se , int pos ,int val){
    if(ss==se)
        st[node] = val;
    else{
        int mid = (ss+se)/2;
        if(pos <= mid){
            update(2*node+1 , ss , mid , pos , val);
        }
        else{
            update(2*node+2 , mid+1 , se , pos , val);
        }
        st[node] = combine(st[2*node+1] , st[2*node+2]);
    }
}

int query(int node , int ss , int se , int l , int r){
    if(l > se || r < ss)      //completely outside
        return inf;
    if(ss >= l && se <= r)    //completely inside
        return st[node];
    int mid = (ss+se)/2;
    return combine(query(2*node+1, ss , mid ,l ,r),query(2*node+2 , mid+1 , se ,l ,r));
}

void Print(int n){ 
    for(int i=0 ; i<=2*n ; i++)
        cout << st[i] << " ";
}

int32_t main(){
    file();
    int n,q; sd2(n,q);
    rep(i , 0 ,n)sd(a[i]);
    build(0 ,0 ,n-1);
    while(q--){
        char c; cin >> c;
        if(c=='q'){
            int u,v; sd2(u,v);
            cout << query(0 , 0 ,n-1 , --u , --v) << endl;
        }
        else{
            int u,v; sd2(u,v); 
            update(0 ,0 ,n-1 , --u,v);
        }
    }
    return 0;
}

