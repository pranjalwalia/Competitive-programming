# Number Theory Logs

### GCD
[GCD basics ](https://codeforces.com/gym/283180)




>***Find the length of the longest subarray with maximum value of gcd.***

###### **Note: gcd(A,B) is maximum and adding more elements to this will lead to either GCD decreasing or staying constant.**
######  Find the max_gcd by iterating over pairs, once computed, iterate again from the start, this time keep checking pairs, when we encounter a pair with gcd == gcd_max, iterate from there till the gcd decreases update length of subarray place the pointer to the point where gcd broke the cycle.
		gcd_max=1;
		// calc max_gcd
		for(int i=0 ; i<n-1 ; i++)
			int g = __gcd(a[i+1] , a[i]);
			if(g > gcd_max) gcd_max=g;
			
		int i;
		int l=0 ; int ans=0;
		for(i=0; i<n-1 ; i++){
			int g = __gcd(a[i] , a[i+1]);
			if(g==gcd_max){
				l=1; i++;
				while(__gcd(g , a[i])==gcd_max && i<n){
					i++; l++;
				}
				i--;
			}
			ans = max(ans , l);
			l=0;
		}` 


<hr/>

> ***Number of Distinct values of  B/gcd(A/B) , a belongs to [1,B]***

The number of distinct values is equal to the number of divisors of B.

<hr>

