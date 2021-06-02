#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long


int main(){
    IOS;
    ll N;
    cin >> N;
    vector<pair<ll,ll>> vp;
    for(ll i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        vp.push_back({b,a});
    }
    sort(vp.begin(),vp.end());
    ll ans=1;
    ll cur = vp[0].first;
    for(ll i=1;i<N;i++){
        if(vp[i].second >= cur){
            ans++;
            cur = vp[i].first;
        }
    }
    cout << ans << endl;

    

    return 0;
}