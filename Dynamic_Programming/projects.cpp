#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

//ll dp[1000001];

void solve(){
    ll N;
    cin >> N;
    ll a[N],b[N],p[N];
    vector<tuple<ll,ll,ll>> vp; 
    for(ll i=0;i<N;i++){
        cin >> a[i] >> b[i] >> p[i];
        vp.push_back({a[i],i,-1});
        vp.push_back({b[i],i,p[i]});
    }
    sort(vp.begin(),vp.end());
    ll dp[N];
    memset(dp,0,sizeof(dp));
    ll j=0;
    for(ll i=1;i<=2*N;i++){
        if(get<2>(vp[j]) != -1){
            dp[i] = max(dp[i-])
        }
    }

}

int main(){
    IOS;

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    ll T=1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}