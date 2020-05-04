/** AWESOME QUESTIONS ON GCD **/


/*
 https://www.codechef.com/problems/GCDMOD 

int power(int x, int y , int p)
{
	int res = 1;	  
	x = x % p; 
	if (x == 0) return 0;                   //call fast_expo(2,5,mod)
	while (y > 0){ 
		if (y & 1) 
			res = (res*x) % p; 
		y = y>>1;							//y = y/2 
		x = (x*x) % p; 
	} 
	return res;
}

int GCD(int A , int B , int n)
{
	if(A == B)
	{
		return (power(A , n , mod) + power(B , n , mod)) % mod;
	}
	
	int cnd = 1;
	int num = A - B;
	
	for(int i=1;i*i<=num;i++)
	if(num % i == 0)
	{
		int temp = (power(A , n , i) + power(B , n , i)) % i;
		
		if(temp == 0) cnd = max(cnd , i);
		
		temp = (power(A , n , num/i) + power(B , n , num/i)) % (num/i);
		if(temp == 0) cnd = max(cnd , num / i);
	}
	
	return cnd % mod;
}

int32_t main(){
    __;
    w(t){
        int a,b,n; sd3(a,b,n);
        cout << GCD(a,b,n) << endl;
    }
    return 0;
}
*/


/*

GCDQ --> gcd queries --> codechef

void GCDQ(){
w(t){
    int n,q; sd2(n,q);
    int a[n]; rep(i ,1 , n+1) sd(a[i]);
    int p[n+100];
    int s[n+100];

    p[0]=0;
    rep(i , 1 , n+1){
        p[i] = __gcd(a[i] , p[i-1]);
    }

    s[n+1]=0;
    for(int i=n ; i>=1 ; i--){
        s[i] = __gcd(s[i+1],a[i]);
    }

    while(q--){
        int l,r; sd2(l,r);
        cout << __gcd(p[l-1] , s[r+1]) << endl;
    }
    
    }    
}


*/