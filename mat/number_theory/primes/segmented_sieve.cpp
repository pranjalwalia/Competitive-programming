/*
 1. Sieve can only generate primes upto 10^6 (limit of global array)
 2. But what if we need upto 10^12..

 When is segmented sieve applicable? 
 1.when N=10^12, but the the query range [L,R] is of size ~10^6 i.e L-R+1 <= 1e6

 Working...
 1. generate all primes till sqrt(R).
 2. create array of size R-L+1 and a[i] = 0 if prime, else a[i]=1;
 3. forEach prime p in range(2,sqrt(R)):
 			for every multiple m of p in range L...R, mark index (m-L) as 1


*/
