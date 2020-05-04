vector<pii>factors;
void primeFact(int N){
    for(int i=2 ; i<=sqrt(N) ; i++){
        if(N%i==0){
            int count=0;
            while(N%i==0){
                count++;
                N/=i;
            }
            factors.pb(mp(i,count));
            // cout << i << "^" << count << endl;
        }
    }
    if(N>1){
        factors.pb(mp(N,1));
        // cout << N << "^" << 1 << endl;
    }
}
  

int32_t main(){
    __;
    primeFact(600851475143);
    rep(i ,0 , factors.size()){
        cout << factors[i].ff << " " << factors[i].ss << endl;
    }
    return 0;
}
