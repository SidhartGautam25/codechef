#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX
 
 
 
ll power(ll x, ll y)
{
    ll temp;
    if (y == 0){
        ll ans=1;
        return ans;
 
    }
       
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return ((temp%mod) * (temp%mod))%mod;
    else{
        ll p1=((x%mod)*(temp%mod))%mod;
        ll p2=((p1%mod)*(temp%mod))%mod;
        return p2;
    }
        
}
 
 
 
 
void dfs1(vector<vector<ll>>&tree,ll curr,ll p,vector<ll>&dp){
    dp[curr]=0;
    ll mmax=0;
    for(ll i=0;i<tree[curr].size();i++){
        ll child=tree[curr][i];
        if(child != p){
            dfs1(tree,child,curr,dp);
            mmax=max(mmax,dp[child]+1);
        }
    }
    dp[curr]=mmax;
}

void dfs(vector<vector<ll>>&tree,ll curr,ll p,vector<ll>&in,vector<ll>&out){
    ll max_dis_1=-1;
    ll max_dis_2=-1;
    for(ll i=0;i<tree[curr].size();i++){
        ll child=tree[curr][i];
        if(child != p){
            if(max_dis_1<in[child]){
                max_dis_2=max_dis_1;
                max_dis_1=in[child];
            }else if(max_dis_2<in[child]){
                max_dis_2=in[child];
            }

        }
    }

    for(ll i=0;i<tree[curr].size();i++){
        ll child=tree[curr][i];
        if(child != p){
            ll max_dis=max_dis_1;
            if(max_dis==in[child]){
                max_dis=max_dis_2;
            }
            out[child]=1+max(out[curr],1+max_dis);
            dfs(tree,child,curr,in,out);
        }
    }
}

void get_prime_factors(ll n,vector<ll>&arr,map<ll,ll>&mp){
     for (ll i = 2; (i * i) <= n; i++)
    {
        if (n % i != 0)
            continue;
        ll c = 0;
        while (n % i == 0)
        {
            n =n/i;
            c++;
        }
        arr.push_back(i);
        mp[i]=c;
    }
    if (n != 1){
        arr.push_back(n);
        mp[n]=1;

    }
        

    sort(arr.begin(), arr.end());
}
 
 
void solve(){
   ll n,k;
   cin>>n>>k;
   if(n%2==1){
      cout<<"-1"<<endl;
      return;
   }
   ll mmin=(n/2)+n;
   if(k<mmin){
    cout<<"-1"<<endl;
    return;
   }else{
     ll rem=k-mmin;
     if(rem%2==1){
        cout<<"-1"<<endl;
        return;
     }else{
         ll t=99998;
        vector<ll>ans(n);
        for(ll i=0;i<n;i++){
            if(i%2==0){
                ll ai=2+min(t,rem);
                rem=rem-min(t,rem);
                ans[i]=ai;
            }else{
                ll ai=1+min(t,rem);
                rem=rem-min(t,rem);
                ans[i]=ai;
            }
        }
        if(rem==0){
            for(int i=0;i<n;i++){
                 cout<<ans[i]<<"  ";

            }
            cout<<endl;
               
            
        }else{
            cout<<"-1"<<endl;
            return;
        }

        
     }
   }
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