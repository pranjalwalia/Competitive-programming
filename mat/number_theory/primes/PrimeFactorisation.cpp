#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define ff  first
#define ss  second
#define pb push_back
#define vi vector<int>

//======================================================//
map<int,int>m;  
void getPrimeFactors(int n){        //O(sqrt(n))
    for(int i=2 ; i*i <= n ; i++){
        if(n%i==0){
            while(n%i==0){
                m[i]++;
                n/=i;
            }
        }
    }
    if(n!=1){
        m[n]++;
    }
}

/**************************************************************************************************************************************************************************************************************/
/*
    PRIME FACTORISATION USING THE SIEVE IN O(logN) TIME
*/
const int K = 100001;
int spf[K];

void sieve_factor(){
    spf[1]=1;
    for(int i=0 ; i<K; i++)
        spf[i]=i;
    for(int i=4 ; i<K ; i+=2){
        spf[i]=2;
    }
    for (int i=3; i*i<K; i++){ 
        if (spf[i] == i){ 
            for (int j=i*i; j<K; j+=i){
                if (spf[j]==j) 
                    spf[j] = i;
            }   
                 
        } 
    } 
}

// return the prime factorization..O(logN) but preprocessing is O(N)..

void getFactorization(int n){
    //vi res;
    while(n != 1){
        //res.pb(spf[n]);
        m[spf[n]]++;
        n/=spf[n];
    }
    //return res;
}

/*
COUNT THE NUMBER OF DIVISORS.. If N = A^i * B^j * C^k...
	then the number of divisors of N = (i+1)*(j+1)*(k+1)...
	1. use a map to store the power of prime factors..
	
	vi ans = getFactorization(24);
	map<int,int>m; 
	rep(i , 0 ,ans.size()) m[ans[i]]++;
	int num_divisors = 1;
	for(auto itr:m){
		num_divisors*=(itr.ss+1);
	}
	tr(num_divisors);


COUNT THE SUM OF DIVISORS OF A NUMBER...
	vi ans = getFactorization(24);
	map<int,int>m; 
	rep(i , 0 ,ans.size()) m[ans[i]]++;
	int sum_divisors = 1;
	for(auto itr:m){
		sum_divisors *= ((itr.ff)**(itr.ss+1)-1)/(itr.ff-1);
	}
*/
 
/***********************************************************************************************************************************************************************/

//divisors of a number
vector<int> divisors(int n){
	vi v;
	for(int i=1; i*i<=n ; i++){
		if(n%i==0){
			v.pb(i);
			if(i != n/i){
				v.pb(n/i);
			}
		}
	}
	return v;
}
//Number of divisors can also be found here by adding a count..

/*****************************************************************************************************************************************/

int main(){
     int N = 576;
     primeFact(N);
     for(int i=0 ; i<factors.size() ; i++)
     cout << factors[i].ff << " " << factors[i].ss << endl;   
     

     sieve_factor(); 
     vector<int> v = getFactorization(576);
     for(int i=0 ; i<v.size() ; i++)
        cout << v[i] << " ";
    cout << endl;


    vi v1 = divisors(576);
}

