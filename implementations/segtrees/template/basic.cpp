#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
int a[N];
int st[4*N];

void Build_min(int si , int ss , int se){
    if(ss==se){
        st[si] = a[ss];
        return;
    }

    int mid = (ss+se)/2;

    Build_min(2*si+1 , ss , mid);
    Build_min(2*si + 2 , mid+1 , se);

    st[si] = min(st[2*si+1] , st[2*si+2]);
}

void Build_sum(int si, int ss, int se) {
    if (ss == se) {
        st[si] = a[ss];

    } else {
        int mid = (ss + se) / 2;

        Build_sum(si*2+1, ss, mid);
        Build_sum(si*2+2, mid+1, se);

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

int rmq(int si , int ss , int se , int qs , int qe){
    if(qs > se || qe < ss)      //completely outside
        return INT_MAX;

    if(ss >= qs && se <= qe)    //completely inside
        return st[si];

    int mid = (ss+se)/2;
    int l = rmq(2*si+1, ss , mid , qs , qe);
    int r = rmq(2*si+2 , mid+1 , se , qs , qe);

    return min(l,r);
}

int sum(int si, int ss, int se, int qs, int qe) {
    if (qs > qe)      //completely outside               
        return 0;

    if (qs == ss && qe == se)   //whole range
        return st[si];

    int mid = (ss + se) / 2;
    return sum(si*2+1, ss, mid, qs, min(qe, mid))
           + sum(si*2+2, mid+1, se, max(qs, mid+1), qe);
}

void Print(int n){ 
    for(int i=0 ; i<=2*n ; i++)
        cout << st[i] << " ";
}

int main(){
    int n; cin >> n;
    for(int i=0 ; i<n ; i++)
        cin>> a[i];
    

}