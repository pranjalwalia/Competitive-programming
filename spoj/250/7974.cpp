
int32_t main(){	
	__;
	file();
	int a,b,c; 
	while(cin >> a and cin >> b and cin >> c){
		if(a==0 and b==0 and c==0){
			return 0;
		}
		if(2*b==a+c){
			int d = c-b;
			cout << "AP" << " " << c+d << endl;
		}
		else {
			int r = c/b;
			cout <<"GP" << " " << r*c << endl;
		}
	}
	return 0;
}
