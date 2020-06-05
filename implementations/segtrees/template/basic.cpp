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

const int N = 10000;
int a[N];
int st[4*N];

void build_min(int si , int ss , int se){
    if(ss==se){
        st[si] = a[ss];
        return;
    }

    int mid = (ss+se)/2;

    build_min(2*si+1 , ss , mid);
    build_min(2*si + 2 , mid+1 , se);

    st[si] = min(st[2*si+1] , st[2*si+2]);
}

void build_max(int si , int ss , int se){
    if(ss==se){
        st[si] = a[ss];
        return;
    }

    int mid = (ss+se)/2;

    build_max(2*si+1 , ss , mid);
    build_max(2*si + 2 , mid+1 , se);

    st[si] = max(st[2*si+1] , st[2*si+2]);
}


void build_sum(int si, int ss, int se) {
    if (ss == se) {
        st[si] = a[ss];
        return;
    } 
    else {
        int mid = (ss + se) / 2;

        build_sum(si*2+1, ss, mid);
        build_sum(si*2+2, mid+1, se);

        st[si] = st[si*2+1] + st[si*2+2];
    }
}

void update_sum(int si , int ss , int se , int pos , int val){
    if(ss==se)
        st[si] = val;
    else{
        int mid = (ss+se)/2;
        if(pos <= mid){
            update_sum(2*si+1 , ss , mid , pos , val);
        }
        else{
            update_sum(2*si+2 , mid+1 , se , pos , val);
        }

        st[si] = st[2*si+1] + st[2*si+2];
    }
}

void update_min(int si , int ss , int se , int pos ,int val){
    if(ss==se)
        st[si] = val;
    else{
        int mid = (ss+se)/2;
        if(pos <= mid){
            update_min(2*si+1 , ss , mid , pos , val);
        }
        else{
            update_min(2*si+2 , mid+1 , se , pos , val);
        }

        st[si] = min(st[2*si+1] , st[2*si+2]);
    }
}

void update_max(int si , int ss , int se , int pos ,int val){
    if(ss==se)
        st[si] = val;
    else{
        int mid = (ss+se)/2;
        if(pos <= mid){
            update_max(2*si+1 , ss , mid , pos , val);
        }
        else{
            update_max(2*si+2 , mid+1 , se , pos , val);
        }

        st[si] = max(st[2*si+1] , st[2*si+2]);
    }
}

int range_min(int si , int ss , int se , int qs , int qe){
    if(qs > se || qe < ss)      //completely outside
        return INT_MAX;

    if(ss >= qs && se <= qe)    //completely inside
        return st[si];

    int mid = (ss+se)/2;
    int l = range_min(2*si+1, ss , mid , qs , qe);
    int r = range_min(2*si+2 , mid+1 , se , qs , qe);

    return min(l,r);
}

int range_max(int si , int ss , int se , int qs , int qe){
    if(qs > se || qe < ss)      //completely outside
        return INT_MIN;

    if(ss >= qs && se <= qe)    //completely inside
        return st[si];

    int mid = (ss+se)/2;
    int l = range_max(2*si+1, ss , mid , qs , qe);
    int r = range_max(2*si+2 , mid+1 , se , qs , qe);

    return max(l,r);
}

int range_sum(int si, int ss, int se, int qs, int qe) {
    if (qs > qe)      //completely outside               
        return 0;

    if (qs == ss && qe == se)   //whole range
        return st[si];

    int mid = (ss + se) / 2;
    return range_sum(si*2+1, ss, mid, qs, min(qe, mid))
           + range_sum(si*2+2, mid+1, se, max(qs, mid+1), qe);
}

void Print(int n){ 
    for(int i=0 ; i<=2*n ; i++)
        cout << st[i] << " ";
}

int32_t main(){
    file();
    int n; cin >> n;
    for(int i=0 ; i<n ; i++)
        cin>> a[i];
}
