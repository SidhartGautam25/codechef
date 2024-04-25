#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void prll(vector<ll>&arr){
    ll n=arr.size();
    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    ll pl=2+k+(k-1)/2;
    ll ans=0;
    ans=3*(n/pl);
    ll rem=n-(pl*(n/pl));
    if(rem==0){
        ans=ans;

    }else if(rem<(k+2)){
        ans=ans+1;

    }else{
        ans=ans+3;
    }
   cout<<ans<<endl;
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