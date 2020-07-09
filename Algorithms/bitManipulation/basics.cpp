//init

bool check_power_of_two(int n)
{
        if(n<=0) return 0;
        // return (ceil(log2(n)) == floor(log2(n))); => slow..
        if(n&(n-1) == 0) return true;
        else return false;
}

void unique_in_vector(){
        //find the unique element in the vector..
        vi v = {5,15,5,3,5,15}; int x=v[0];
        rep(i ,0,v.size()){
                x^=v[i];
        }
        tr(x);
}

void find_duplicate(){
        vi v = { 23 , 21 , 24 , 27 , 22 , 27 , 26 , 25 };
        /*
                Algo: use the facts that n^n=0 and n^0=n.

                1. find the min and max in the array => O(N).
                2. find the xor of all integers in range [min,max] => x = min^(min+1)^....^(max).
                3. find the xor of all elements in the array => y = a[0]^a[1]^a[2]...^a[n-1].
                4. ans = x^y;
        */
}

void odd_or_even(int n){
        //check odd and even..
        //(n&1) => odd
        //(!(n&1)) => even
        //((n&1)^1) => even
}

void count_set_bit(int n){      //better way is to use bitset..
        //dry run this..count the number of set bits in a number..
        int count=0;
        while(n>0){
                if(n&1){
                        count++;
                }
                n>>1;
        }
}

int count_set_alternate(int n){
        // n&(n-1) => drops the last set bit (lsb)..
        // eg: 14(1110) => 12(1100)
        int count=0;
        while(n>0){
                // in each cycle, the lsb is dropped...
                count++;
                n = (n&(n-1));
basics.cpp [dos] (14:21 07/07/2020)                                                                                                                                                                   80,21-28 64%

