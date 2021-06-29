#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

//ll dp[5001][5001];

void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    vector<ll> dp;
    for(ll i=0;i<N;i++){
        auto it = lower_bound(dp.begin(),dp.end(),a[i]);
        if(it == dp.end()){
            dp.push_back(a[i]);
        }
        else{
            *it = a[i];
        }
    }
    cout << dp.size() << endl;


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