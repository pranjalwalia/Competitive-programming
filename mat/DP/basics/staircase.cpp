/*
    GIVEN A STAIRCASE, NUMBERED FROM ZERO , FIND THE NUMBER OF WAYS OF REACHING FORM THE ZEROTH
    STEP TO ANY GIVEN N STEP.

		SIMILAR TO SIEVE --> PRE-PROCESSING TIME O(N), ANSWER QUERIES IN O(q);
*/

const int N = 100001;
int dp[N];

int32_t main(){
	__;	
	dp[1] = 1;
	dp[2]=2;
	for(int i=3 ; i<N ; i++){
		dp[i]=dp[i-2]+dp[i-1];
	}
	ans = dp[10];
	tr(ans);
	return 0;
}
