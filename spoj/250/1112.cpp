void solve(){
	int x,y;sd2(x,y);
	if(x-y==2 || x-y==0){
		if(x&1 and y&1){
			cout << x+y-1 << endl;
		}
		else if(!(x&1) and !(y&1)){
			cout << x + y << endl;
		}
		else cout << "No Number" << endl;
	}
	else{
		cout << "No Number" << endl;
	}
}

int32_t main(){	
	__;
	file();
	w(t){
		solve();
	}
	return 0;
}
