int left(int a[] ,int i , int n){
    if(i==0)
        return 0;
    int s=0;
    for(int j=i-1 ; j>=0; j--){
        if(abs(a[j+1]-a[j]) <= 2)
            s++;
        else break;
    }
    return s;
}


int right(int a[] ,int i , int n){
    if(i==n-1)
        return 0;
    int s=0;
    for(int j=i+1 ; j<n; j++){
        if(abs(a[j-1]-a[j]) <= 2)
            s++;
        else break;
    }
    return s;
}

void COVID19(){
     w(t){
        int ans1=numeric_limits<int>::max();
        int ans2=numeric_limits<int>::min();
        int n; sd(n);
        int a[n]; FOR(i ,0 ,n)sd(a[i]);
        
        for(int i=0; i<n ; i++){
            int tot=1;
            tot += (right(a,i,n) + left(a,i,n));
            ans1 = min(ans1 , tot);
            ans2 = max(ans2 , tot);
        }
        tr2(ans1,ans2);
    }
}

