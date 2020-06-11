#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define ff  first
#define ss  second
#define pb push_back


vector<pii>factors;
void primeFact(int N){                  //O(sqrtN)
    for(int i=2 ; i*i<=(N) ; i++){
        if(N%i==0){
            int count=0;
            while(N%i==0){
                count++;
                N/=i;
            }
            factors.pb(mp(i,count));
            // cout << i << "^" << count << endl;
        }
    }
    if(N>1){
        factors.pb(mp(N,1));
        // cout << N << "^" << 1 << endl;
    }
}

/*********************************************************************************************************************************/
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
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}
 
/*****************************************************************************************************************************************/

//divisors of a number
vi divisors(int n){
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


    findDivisors(576);
}

