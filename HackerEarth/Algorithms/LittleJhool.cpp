#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ve vector<int>
#define vl vector<long long int>
#define pb push_back
#define fo(i,a,n) for(i=a;i<n;i++)

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,b,g;
        cin>>n;
        cin>>b>>g;
        if(abs(b-g)>=2)cout<<"Little Jhool wins!"<<endl;
        else cout<<"The teacher wins!"<<endl;
    }
}
