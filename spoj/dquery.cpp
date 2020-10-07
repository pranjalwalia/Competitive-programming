#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <bits/stdc++.h>
#include <map>
#include <stack>
 
using namespace std;
 
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define ll long long
 
 
/*--------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------*/
int a[1000000];
int n;
struct nodost
{
	int sum;
};
nodost nodo[1000000];
 
struct query
{
	int l,r,id;
 
	bool operator <(query  b){
		return r<b.r;
	}
};
 
struct fo
{
	int val,next;
 
	bool operator <(fo  b){
		return (val<b.val || (val==b.val && next<b.next));
	}
};
fo b[1000000];
query querys[1000006];
int ant[1000006];
 
nodost merge(nodost l, nodost r){
 
	nodost resp;
 
	resp.sum=l.sum+r.sum;
 
	return resp;
}
 
nodost hoja(int l){
 
	nodost resp;
 
	resp.sum=a[l];
	
	return resp;
}
 
void buildst(int l,int r,ll indexst){ 
	if(l==r){
		nodo[indexst]=hoja(l);
		return;
	}
	ll left=2*indexst, right=2*indexst+1;
	int med= (l+r)/2;
	buildst(l,med,left); 
	buildst(med+1,r,right);
	nodo[indexst]=merge(nodo[left],nodo[right]);
}
 
void update(int u,int l,int r,ll indexst){ 
	if(l==u && r==u){
		nodo[indexst]=hoja(u);
		return;
	}
	ll left=2*indexst, right=2*indexst+1;
	int med= (l+r)/2;
	if(u<=med)
	update(u,l,med,left); 
	else
	update(u,med+1,r,right);
	nodo[indexst]=merge(nodo[left],nodo[right]);
}
 
nodost getsum(ll indexst, int left,int right,int l,int r){
 
	if (left == l && right == r)
    	return nodo[indexst];
  	
	  int med = (left + right) / 2;
	  if (l > med)
	    return getsum(2*indexst+1, med+1, right, l, r);
	  if (r <= med)
	    return getsum(2*indexst, left, med, l, r);
	  	
	  nodost lresp = getsum(2*indexst, left, med, l, med);
	  nodost rresp = getsum(2*indexst+1, med+1, right, med+1, r);
	  nodost result= merge(lresp, rresp);
 
	return result;
}
 
void fix(int r,int u){
	//
	ROF(i,u,r){
		int x=b[i].next;
		if(x>0){
			a[x]=1;
			update(x,1,n,1);
		}
	}
}
 
int main(){
 
	ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
 
	cin>>n; int c;
 
	FOR(i,1,n+1){
 
		cin>>c;
		
		b[i]={c,ant[c]};
		ant[c]=i;
		
	}
 
	memset(ant,-1, sizeof ant);
	//arreglar array a
	ROF(i,n,0){
		if(ant[b[i].val]==-1){
			a[i]=1;
			ant[b[i].val]=1;
		}else a[i]=0;
	}	
 
	//hacer segment tree
	buildst(1,n,1);
	int m;
	cin>>m;
	int l,r,ract=n;
	int re[m];
 
	FOR(i,0,m){
		cin>>l>>r;
		querys[i]={l,r,i};
	}
 
	sort(querys,querys+m);
 
	ROF(i,m-1,-1){
		int r=querys[i].r, l=querys[i].l, id=querys[i].id;
		if(r<ract) fix(r,ract); //updates
		ract=r;
		re[id]=getsum(1,1,n,l,r).sum;//solve querys
	}
 
	FOR(i,0,m) cout<<re[i]<<"\n";
 
	return 0;
}
