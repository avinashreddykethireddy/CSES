

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define all(x) begin(x),end(x)

// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892
ll tree[400001];


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
    ll arr[N+1];    
    memset(tree,0,sizeof(tree));
    ll temp[N+1];
    for(ll i=1;i<=N;i++){
        cin >> arr[i];
        temp[i] = arr[i];
    }
    for(ll i=2;i<=N;i++){
        arr[i] -=temp[i-1]; // difference array
    }
    for(ll k=1;k<=N;k++){
        addK(k,arr[k],N);
    }

    while(Q--){
        ll v,u,a,b;
        cin >> v;
        if(v == 1){
            cin >> a >> b >> u;
            // update
            addK(a,u,N);
            addK(b+1,-u,N);
        }
        else if(v == 2){
            cin  >> u;
            // get
            cout << sumK(u) << endl;
        }

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