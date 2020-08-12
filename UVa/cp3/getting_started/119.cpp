
int32_t main(){	
	__;
	file();
	int t=1;
	int n;
	while(cin>>n){
		string s[n];
		map<string,int>m;
		for(int i=0 ; i<n ; ++i){
			cin>>s[i];
			m[s[i]]=0;
		}
		string p;
		for(int i=0 ; i<n ; ++i){
			cin>>p;
			int money,ppl; cin>>money>>ppl;
			int a=0,b=0;
			if(ppl !=0){
				int a = (int)floor(money/ppl);
				int b = a*ppl;	
				for(int i=0; i<ppl ; ++i){
					string temp; cin>>temp;
					m[temp]+=(a);
				}
				m[p]-=b;
			}
		}
		if(t++ > 1){
			cout << endl;
		}
		for(int i=0 ; i<n ; ++i){
			cout << s[i] << " " << m[s[i]] << endl;
		}
	} 
	
	return 0;
}

