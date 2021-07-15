#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define all(x) begin(x),end(x)

// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

ll tree[200002];


ll sumK(ll k){
    ll sum=0;
    while(k >= 1){
        sum += tree[k];
        k -= k&-k;
    }
    return sum;
}

void addK(ll k,ll x,ll N){
    while(k <= N){
        tree[k] += x;
        k += k&-k;
    }
}

void solve(){
    ll N,Q;
    cin >> N >> Q;
    ll a[N+1];
    for(ll i=1;i<=N;i++){
        cin >> a[i];
    }

    memset(tree,0,sizeof(tree));
    // tree[k] = sumq(k-p(k)+1,k) binary indexed trees
    for(ll k=1;k<=N;k++){
        addK(k,a[k],N);
    }
    while(Q--){
        ll a,b;
        cin >> a >> b;
        ll ans = sumK(b) - sumK(a-1);
        cout << ans << endl;
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