/*
URL
https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/k-th-bit-faae0e0d/description/
*/
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
#define __              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b) 		for(int i=a;i<b;i++)
#define repb(i,a,b) 	for(int i=a;i>=b;i--)
#define endl			"\n"

void file(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
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

void build(int node,int start,int end,int tree[],int a[])
{
    if(start==end)
        tree[node]=a[start];

    else{
        int mid=(start+end)/2;
        build(2*node ,start ,mid ,tree ,a); 
        build(2*node+1, mid+1, end, tree, a);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node,int start,int end,int idx,int val,int tree[],int a[])
{
    if(start==end){
        a[idx]=val;
        tree[node]=val;
    }
    else
    {
        int mid = (start+end)/2;
        if(idx >= start && idx <= mid)
            update(2*node , start, mid ,idx, val, tree, a);
        else
            update(2*node+1, mid+1, end, idx, val, tree, a);

        tree[node] = tree[2*node] + tree[2*node+1];
    }

}

int query(int node , int s ,int e , int k , int tree[]){

	if(s==e && k==1)
		return e;

	int m = (s+e)/2;
	if(tree[2*node] < k){
		return query(2*node+1 , m+1,e,k-tree[2*node] , tree);
	}
	else{
		return query(2*node , s , m , k , tree);
	}
}

int32_t main(){	
	__;
	int n,q; cin >> n >> q;
	int a[n];
	int m = 4*n;
	int seg[m];
	rep(i,1,n+1){
		a[i]=1;
	}
	build(1,1,n,seg,a);

	int x,y;
	while(q--){
		cin >> x>>y;
		if(x==0){
			update(1,1,n,y,0,seg,a);
		}
		else{
			if(seg[1] < y){
				cout << -1 << endl;
			}
			else{
				cout << query(1,1,n,y,seg) << endl;
			}
		}
	}
	
}