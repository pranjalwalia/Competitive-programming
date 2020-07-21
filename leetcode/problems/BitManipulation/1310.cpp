//1310. XOR Queries of a Subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>p(arr.size() ,0); 
        p[0]=arr[0];
        for(int i=1 ; i<arr.size() ; i++){
            p[i] = p[i-1]^arr[i];
        }
        for(int i=0 ; i<queries.size() ; i++){
            int l = queries[i][0]; int r = queries[i][1];
            if(l==0){
                ans.push_back(p[r]);
            }
            else ans.push_back(p[r]^p[l-1]);
        }
        return ans;
    }
};
