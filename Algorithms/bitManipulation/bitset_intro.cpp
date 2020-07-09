}

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define deb3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

bool is_pal(string s) {return equal(all(s), s.rbegin());}

int mypow(int a, int b){        //(logn) fast exponentiation
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

int32_t main(){
        __;
        file();
        int n; sd(n);
        bitset<32> b(n);

        cout << b.to_string() << endl;
        cout << b.to_ulong() << endl;   //unsigned long
        cout << b.to_ullong() << endl;  //unsigned long long



        return 0;
}

/*
        Intro to bitset..1e9 => 32 bit..
        bitset<size> name(n);   //indexing from lsb..

        1. bitset can directly store n in binary form..
        2. following conversions are possible: decimal => binary, binary=>string, binary=>decimal.
        3. modifications in bitset also possible...
*/


bitset_intro.cpp [dos] (03:47 07/07/2020)                                                                                                                                                             86,14-21 Bot

