

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define all(x) begin(x),end(x)

// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892



void solve(){
    ll N,Q;
    cin >> N >> Q;
    ll arr[N+1];
    arr[0] = 0;
    for(ll i=1;i<=N;i++){
        cin >> arr[i];
    }
    for(ll i=2;i<=N;i++){
        arr[i] ^= arr[i-1];
    }
    // for(ll i=0;i<N;i++){
    //     cout << arr[i] << " \n"[i==N-1];
    // }
    while(Q--){
        ll a,b;
        cin >> a >> b;

        cout << (arr[b]^arr[a-1]) << endl;

    }    
}

signed main() {
    IOS;

    ll T=1;
    //cin >> T;
    while(T--){
        solve();
    }

    return 0;
}