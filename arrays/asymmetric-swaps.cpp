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
void take_input(vector<ll>&arr){
    ll n=arr.size();
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    take_input(a);
    take_input(b);
    vector<ll>all(2*n);
    for(ll i=0;i<n;i++){
        all[i]=a[i];
        all[i+n]=b[i];
    }
    sort(all.begin(),all.end());
    ll ans=all[n-1]-all[0];
    for(ll i=1;i<=n;i++){
        ans=min(ans,all[i+n-1]-all[i]);
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