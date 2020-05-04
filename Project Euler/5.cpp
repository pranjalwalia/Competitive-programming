int32_t main(){
    __;
    int ans=1;
    rep(i ,1 , 21){
        ans = ((ans*i)/__gcd(ans,i));
    }
    tr(ans);
    return 0;
}
