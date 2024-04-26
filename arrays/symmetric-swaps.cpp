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
    /*
    my solution 

    vector<pair<ll,ll>>ap(n);
    for(ll i=0;i<n;i++){
        ap[i].first=a[i];
        ap[i].second=b[i];
    }
    sort(ap.begin(),ap.end());
    ll ans=ap[n-1].first-ap[0].first;
    ll opt1=ap[0].first;
    ll llim=0;
    ll ulim=0;
    vector<ll>sym;
    for(ll i=1;i<n;i++){
        ll x=ap[i].first;
        ll y=ap[i].second;
        if(x<=(opt1+ulim)){
            continue;
        }else if(y>=(opt1-llim)&&(y<=(opt1+ulim))){
            continue;
        }else{
            if((x-opt1)==(opt1-y)){
                sym.push_back(i);
                continue;
            }
            else if(y>=x){
                ulim=max(ulim,x-opt1);
            }else if(y<=opt1){
                if((opt1-y)<(x-opt1)){
                    llim=max(llim,opt1-y);
                }else{
                    ulim=max(ulim,x-opt1);
                }
            }else{
                ulim=max(ulim,y-opt1);
            }
        }
    }
    if(sym.size()>0){
        ll s=sym.size();
        for(ll i=0;i<s;i++){
            ll t1=ap[sym[i]].first;
            ll t2=ap[sym[i]].second;
            if(t1<=(opt1+ulim)){
                continue;
            }else if(t2>=(opt1-llim)){
                continue;
            }else{
                ll nulim=t1-opt1;
                ll nllim=opt1-t2;
                if((nulim-ulim)<=(nllim-llim)){
                    ulim=nulim;
                }else{
                    llim=nllim;
                }
            }
        }
    }
    ans=min(ans,llim+ulim);
    llim=0;
    ulim=0;
    ll opt2=ap[0].second;
    vector<ll>sec;
    for(ll i=1;i<n;i++){
        ll x=ap[i].first;
        ll y=ap[i].second;
        if(((opt2-llim)<=x)&&((opt2+ulim)>=x)){
            continue;
        }else if((y<=(opt2+ulim))&&(y>=(opt2-llim))){
            continue;
        }else{
            if(x>opt2){
                if((x-opt2)==(opt2-y)){
                    sec.push_back(i);
                    continue;
                }
            }else if(y>opt2){
                if((y-opt2)==(opt2-x)){
                    sec.push_back(i);
                    continue;
                }
            }
            //if we take x
            if(x>=opt2){
                if(y>=opt2){
                    if(x<=y){
                        ulim=max(ulim,x-opt2);
                    }

                }else{
                    if((x-opt2)<=(opt2-y)){
                        ulim=max(ulim,x-opt2);
                    }

                }

            }else{
                if(y<=opt2){
                    if(x>=y){
                        llim=max(llim,opt2-x);
                    }

                }else{
                    if((opt2-x)<=(y-opt2)){
                        llim=max(llim,opt2-x);
                    }

                }

            }

            //if we take y
            if(y>=opt2){
                if(x>=opt2){
                    if(y<=x){
                        ulim=max(ulim,y-opt2);
                    }
                }else{
                    if((y-opt2)<=(opt2-x)){
                        ulim=max(ulim,y-opt2);
                    }
                }

            }else{
                if(x<=opt2){
                    if(y>=x){
                        llim=max(llim,opt2-y);
                    }
                }else{
                    if((opt2-y)<=(x-opt2)){
                        llim=max(llim,opt2-y);
                    }
                }

            }

        }
    }
   // cout<<"befor same ulim "<<ulim<<" llim "<<llim<<endl;
    if(sec.size()>0){
        ll s=sec.size();
        for(ll i=0;i<s;i++){
            ll t1=ap[sec[i]].first;
            ll t2=ap[sec[i]].second;
            ll x=max(t1,t2);
            ll y=min(t1,t2);
            if(x<=(opt2+ulim)){
                continue;
            }else if(y>=(opt2-llim)){
                continue;
            }else{
                ll tulim=x-opt2;
                ll tllim=opt2-y;
                if((tulim-ulim)<=(tllim-llim)){
                    ulim=tulim;
                }else{
                    llim=tllim;
                }
            }
        }
    }
    ans=min(ans,ulim+llim);
    cout<<ans<<endl;

    */
    vector<pair<ll,ll>>c;
    for(ll i=0;i<n;i++){
        c.push_back(make_pair(a[i],i));
        c.push_back(make_pair(b[i],i));
    }
    sort(c.begin(),c.end());
    ll count=0;
    vector<ll>check(n,-1);
    vector<ll>freq(n,0);
    ll l=0;
    ll r=0;
    ll ans=LLONG_MAX;
    while(r<2*n && l<=r){
        ll ind=c[r].second;
        ll val=c[r].first;
        //cout<<"for r "<<r<<" ind "<<ind<<" val "<<val<<endl;
        //cout<<"for l "<<l<<" and r "<<r<<" count is "<<count<<" ans "<<ans<<endl;
        if(check[ind]==-1){
            check[ind]=1;
            count++;
            freq[ind]++;
            if(count==n){
                while(count==n){
                    ll temp=c[r].first-c[l].first;
                    //cout<<"ans is "<<temp<<endl;
                    ans=min(ans,c[r].first-c[l].first);
                    freq[c[l].second]--;
                    if(freq[c[l].second]==0){
                    count--;
                    check[c[l].second]=-1;
                   
                    }
                    l++;

                }
               
            }
        }else{
            freq[ind]++;
        }
        r++;

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