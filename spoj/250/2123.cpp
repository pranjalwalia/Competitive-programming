
int32_t main(){	
	__;
	file();
	int n;
	while(cin>>n)
	{
		if(n==-1){
			return 0;			
		} 
		else{
			int ans=0;
			int a[n];
			for(int i=0 ; i<n ; ++i){
				int x; sd(x); ans+=x;
				a[i]=x;
			}
			if(ans%n){
				cout << -1 << endl;
			}
			else{
				int s=ans; ans=0;
				int k=s/n;
				rep(i,0,n){
					if(a[i] > k){
						ans+=(a[i]-k);
					}
				}
				cout << ans<<endl;
			}

		}
	}
	return 0;
}
