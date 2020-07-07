//338. Counting Bits => DP solution in O(N).

/*
    n&(n-1) drops the lsb, i.e reduces the number of bits by 1.
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>ans(num+1,0);
        //ans[0]=0; ans[1]=1;
        for(int i=1; i<num+1 ; ++i){
            ans[i] = ans[i&(i-1)]+1;    
        }
        return ans;
    }
};
