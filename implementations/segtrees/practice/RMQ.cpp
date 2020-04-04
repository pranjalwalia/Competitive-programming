#include<bits/stdc++.h>
using namespace std;

void build(int st[] , int a[] , int index , int s , int e){
    if(s>e){
        return;
    }
    if(s==e){
        st[index] = a[s];
        return;
    }

    int m = (s+e)/2;
    build(st,a,2*index, s, m);
    build(st,a,2*index+1, m+1 , e);

    int left = st[2*index];
    int right = st[2*index+1];

    st[index] = min(left , right);
}

int RMQ(int *tree,int index,int s,int e,int qs,int qe){
    ///No Overlap
    if(qs>e || qe<s){
        return INT_MAX;
    }
    ///Complete Overlap
    if(qs<=s && qe>=e){
       return tree[index];
    }

    ///Partial Overlap
    int mid = (s+e)/2;
    int leftAns = RMQ(tree,2*index,s,mid,qs,qe);
    int rightAns = RMQ(tree,2*index+1,mid+1,e,qs,qe);

    return min(leftAns,rightAns);
}

void updateNode(int *tree,int index,int s,int e,int i,int value){
    if(i<s||i>e){
        return;
    }
    if(s==e){
        tree[index] = value;
        return;
    }
    /// i is lying in the range s to e
    int mid = (s+e)/2;
    updateNode(tree,2*index,s,mid,i,value);
    updateNode(tree,2*index+1,mid+1,e,i,value);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}


/// increment every value in the given range
void updateRange(int *tree,int index,int s,int e,int rs,int re,int inc){
    ///No Overlap
    if(re< s || rs>e){
        return ;
    }
    ///Leaf Node
    if(s == e){

        tree[index] += inc;
        return;
    }
    //lying in range--call both sides
    int mid = (s + e )/2;
    updateRange(tree,2*index,s,mid,rs,re,inc);
    updateRange(tree,2*index+1,mid+1,e,rs,re,inc);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}


void Print(int st[] , int n){
    for(int i=1 ; i<=2*n+1 ; i++){
        cout << st[i] << " ";
    }
}

int main(){
    
    int a[] = {1,3,2,-2,4,5};
    int n = sizeof(a)/sizeof(int);
    
    int *st = new int[4*n+1];   //initialises to 0

    int index=1;
    int s=0;
    int e=n-1;
    build(st,a,index,s,e);
    // Print(st,n);
    // updateNode(st,index,0,n-1,3,10);
    cout << RMQ(st,index,0,n-1,0,n-1);
    
}
