int func(int a[] , int n){
    int s=0;
    int ans=0;
    rep(i , 0 , n)
        s+=a[i];
    if(s%n!=0)
        return -1;
    else{
        rep(i , 0, n){
            if((s)/n - a[i] >= 0){
                ans+=((s)/n - a[i]);
            }
            else continue;
        }
        return ans;
    }
}

