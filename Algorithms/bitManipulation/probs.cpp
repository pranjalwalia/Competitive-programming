void generate(string s){
        int l = s.length();
        int range = (1<<l)-1;
        for(int i=0 ; i<=range ; i++){  //O(2^n)
                print_seq(s,i);                         //O(N)
                cout << endl;
        }
        //O(2^N * N);
}
/*
int32_t main(){
        __;
        file();
        string s = "xyz";
        generate(s);
        return 0;
}
*/

// Q2.  Haming distance(HD)..in a bitset of a and b , if(a[i] != b[i]) HD++;
//Ques. => sum of pairwise haming distance of n integers.





//Q3. In an array, check if there is any combination of elements such that sum=k.
        // =>generate all possible combinations and check using bits..
bool checkSum(int a[] , int n , int k){
        for(int i=0 ; i<(1<<n) ; i++)
        {
                int curr=i; int sum=0; int x=0;
                //if jth bit is set, include it in the sum, else dont include it.
                while(curr>0){
                        if(curr&1){
                                sum+=a[x];
                        }
                        x++;
                        curr = curr>>1;
                }
                if(sum==k) return true;
        }
        return false;
}

int32_t main(){
        __; file();
        int a[] = {3,4,1,2}; int n = sizeof(a)/sizeof(a[0]);
        int k=6;
        cout << checkSum(a,n,k) << endl;
}





probs.cpp [dos] (14:30 07/07/2020)                                                                                                                                                                      125,39 Bot

