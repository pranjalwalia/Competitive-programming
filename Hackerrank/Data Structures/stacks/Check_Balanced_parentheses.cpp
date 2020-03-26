#include<bits/stdc++.h>
using namespace std;

bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

int balanced(string s){
    stack<char>st;
    for(int i=0 ; i<s.length() ;i++){
        if(s[i] == '(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i] == ')' || s[i]=='}' || s[i]==']'){
            if(st.empty() || !ArePair(st.top() , s[i])){
                return 0;
            }
            else{
                st.pop();
            }
        }
    }
    if(st.empty()){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
    cin >> s;
    if(balanced(s)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    }
    
}
