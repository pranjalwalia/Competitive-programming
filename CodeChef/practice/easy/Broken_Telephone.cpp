#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve();
void scan(int arr [] , int n)
{for(int i=0; i<n; i++)cin>>arr[i];}
void print(int arr [] , int n)
{for(int i=0; i<n; i++)cout<<arr[i];}
ll n;
#define rep for(int i=0; i<n; i++)
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t;
cin>>t;
while(t--)
{
solve();
}
return 0;
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    scan(arr,n);
    int ans=0;
    for(int i=1; i<n-1; i++)
    {
        if(arr[i]!=arr[i-1] || arr[i]!=arr[i+1])ans++;
    }
    if(arr[0]!=arr[1])ans++;
    if(n>2){
        if(arr[n-1]!=arr[n-2])ans++;
    }
    cout<<ans<<endl;
}
