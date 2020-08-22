void solve(){
	vi a = {1,3,0,0,1,2,4};
	vi ans;
	stack<int>s;
	for(int i=(int)a.size()-1 ; i>=0 ; i--){
		if(s.empty())
			ans.pb(-1);
		else if(!s.empty() and s.top() > a[i])
			ans.pb(s.top());		
		else{
			while(!s.empty() and s.top() <= a[i])
				s.pop();

			if(s.empty())
				ans.pb(-1);
			else ans.pb(s.top());
		}
		s.push(a[i]);
	}
	reverse(all(ans));
}	

