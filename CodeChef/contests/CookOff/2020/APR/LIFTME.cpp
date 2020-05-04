void COOK_APR_A(){
    w(t){
        int n,q; sd2(n,q);
        int curr=0;
        int ans=0;
        while(q--){
            int fi,di; sd2(fi,di);
            ans+=(abs(curr-fi));
            curr = fi;
            ans+=(abs(di-curr));
            curr = di;
        }
        tr(ans);
    }
}

