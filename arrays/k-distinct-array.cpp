#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


void solve(){
    ll n,k;
    cin>>n>>k;
    k=k-n;
    vector<ll>ans;
    ll x=(1+sqrtl(1+8*k))/2;
    ll size=0;
    for(ll i=0;i<x;i++){
        ans.push_back(i+1);
        size++;
    }
    ll rem=k-((x*(x-1))/2);
    if(rem != 0){
        ll last=x-rem;
        ans.push_back(last);
        size++;
        for(ll i=size;i<n;i++){
            ans.push_back(last);
            
        }


    }
    size=ans.size();
   // cout<<"size "<<size<<" n "<<n<<endl;
    for(ll i=size;i<n;i++){
        ans.push_back(x);
    }
   // cout<<"ans"<<endl;
    for(ll i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
     }

    return 0;
}