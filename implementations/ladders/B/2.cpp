void CF_197_D2(){
    int n,m; sd2(n,m);
    int a[m];
    FOR(i , 0 ,m)sd(a[i]);
    int ans=0;
    ans+=(a[0]-1);
    
    FOR(i ,0 ,m-1){
        if(a[i+1] >= a[i]){
            ans+=(a[i+1]-a[i]);
        }
        else{
            ans+=(n-a[i]+a[i+1]);
        }
    }
    tr(ans);
}

