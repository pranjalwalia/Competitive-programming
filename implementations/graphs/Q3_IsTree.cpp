void dfs(int node){
    vis[node]=1;
    for(auto child : g[node]){
        if(!vis[child])
            dfs(child);
    }   
}

int n,e; sd2(n,e);
    if(e!=n-1){
        cout << "NO" << endl;
        return 0;
    }
    for(int i=0 ; i<e ; i++){
        int u,v;sd2(u,v);
        u--; v--;
        g[v].pb(u); g[u].pb(v);
    }
    int c=0;
    FOR(i ,0 , n){
        if(!vis[i]){
            dfs(i); c++;
        }
    }
    if(c==1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
