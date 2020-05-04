void GCDQ(){
w(t){
    int n,q; sd2(n,q);
    int a[n]; rep(i ,1 , n+1) sd(a[i]);
    int p[n+100];
    int s[n+100];

    p[0]=0;
    rep(i , 1 , n+1){
        p[i] = __gcd(a[i] , p[i-1]);
    }

    s[n+1]=0;
    for(int i=n ; i>=1 ; i--){
        s[i] = __gcd(s[i+1],a[i]);
    }

    while(q--){
        int l,r; sd2(l,r);
        cout << __gcd(p[l-1] , s[r+1]) << endl;
    }
    
    }
    
}

