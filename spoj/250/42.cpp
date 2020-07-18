//42 on spoj

int rev(int n){
	//reverse a number..
	int s=0;
	while(n){
		//s = n%10, s = 
		s = s*10 + n%10;
		n/=10;
	}
	return s;
}

void solve(){
	int n,m; sd2(n,m);
	//get the reverse..
	cout << rev(rev(n) + rev(m)) << endl;
}
