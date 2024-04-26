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
void take_input(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    take_input(a);
    take_input(b);
    vector<pair<int,int>>ap(n);
    for(int i=0;i<n;i++){
        ap.first=a[i];
        ap.second=b[i];
    }
    sort(ap.begin(),ap.end());
    int ans=INT_MAX;
    int mmin=a[0];
    int limit=0;
    for(int i=0;i<n;i++){
        int t=mmin;
        mmin=min(mmin,max(ap.first,ap.second));
        if(mmin != t){
            limit=i;
        }
    }
    for(int i=n-1;i>limit;i--){
        mmax=max(mmax,min(ap[i].first,ap[i].second));
    }
    ans=mmax-mmin;
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