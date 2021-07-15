#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define all(x) begin(x),end(x)

// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

ll tree[400002];

ll minq(ll a,ll b, ll N){
    a += N;
    b += N;
    ll minimum=INT_MAX;
    while(a <= b){
        if(a%2 == 1){
            minimum = min(minimum,tree[a++]);
        }
        if(b%2 == 0){
            minimum = min(minimum,tree[b--]);
        }
        a/=2;
        b/=2;
    }
    return minimum;
}

void add(ll k,ll x,ll N){
    //k += N;
    tree[k] = x;
    for(k = k/2;k>=1;k = k/2){
        tree[k] = min(tree[2*k],tree[2*k+1]);
    }
}

void solve(){
    ll N,Q;
    cin >> N >> Q;
    ll a[N];
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    
    for(ll i=0;i<=2*N;i++){
        tree[i] = INT_MAX;
    }
    for(ll i=0;i<N;i++){
        add(i+N,a[i],N);
    }
    //memset(tree,0,sizeof(tree));
    // tree[k] = sumq(k-p(k)+1,k) binary indexed trees
    // for(ll i=0;i<=2*N;i++){
    //     cout << tree[i] << " \n"[i==2*N];
    // }
    while(Q--){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            add(b-1+N,c,N);
        }
        else if(a == 2){
            cout << minq(b-1,c-1,N) << endl;
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