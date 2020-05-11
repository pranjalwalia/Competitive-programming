// Queing at school
// https://codeforces.com/contest/266/problem/B
 
void queing(){
int n,t; sd2(n,t);
    string s; cin >> s;
    while(t--){
        for(int i=0 ; i<n-1 ; ){
            if(s[i+1]=='G' && s[i]=='B'){
                s[i+1]='B'; s[i]='G';
                i+=2;
            }
            else i++;
        }
    }
    cout << s << endl;
}
