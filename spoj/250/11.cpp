//11
void solve(){
	int n; sd(n);
	int ans=0;
	int p =5;
	for(int i=1 ; ; ++i){
		if(floor(n/pow(p,i)) == 0){
			cout << ans << endl;
			return;
		}
		ans+=floor(n/pow(p,i));
	}
}
