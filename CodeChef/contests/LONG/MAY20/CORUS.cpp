void CORUS(){
w(t){
        int n,q; sd2(n,q);
        string s; cin >> s;
        vi v(26,0);
        FOR(i ,0 ,n){
            v[s[i]-'a']++;
        }
        while(q--){
            int x; sd(x);
            int ans=0;
            FOR(i ,0 ,26){
                if(v[i] > x){
                    ans += (v[i]-x);
                }
            }
            tr(ans);
        }

    }
}

