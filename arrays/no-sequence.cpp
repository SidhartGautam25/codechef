#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void print(vector<ll>&arr){
    ll n=arr.size();
    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    ll n,k,s;
    cin>>n>>k>>s;
    vector<ll>ans(n);
    ll ss=s;
    for(ll i=0;i<n;i++){
        ll t=ss%k;
        if((t==0)||(t==1)){
            ans[i]=t;
            ss=(ss-t)/k;
        }else{
            ans[i]=-1;
            ss=(ss+1)/k;
        }
    }
    ll sum=0;
    ll kk=1;
    for(ll i=0;i<n;i++){
        sum=sum+ans[i]*kk;
        kk=kk*k;
        if(sum>=s){
            break;
        }
        
    }
    //cout<<"sum "<<sum<<" s "<<s<<endl;
    if(sum==s){
        print(ans);
        return;
    }
    cout<<"-2"<<endl;
    return;
    
   
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