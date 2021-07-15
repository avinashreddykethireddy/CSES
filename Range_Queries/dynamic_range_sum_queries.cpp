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

ll sumq(ll a,ll b, ll N){
    a += N;
    b += N;
    ll sum=0;
    while(a <= b){
        if(a%2 == 1){
            sum += tree[a++];
        }
        if(b%2 == 0){
            sum += tree[b--];
        }
        a/=2;
        b/=2;
    }
    return sum;
}

void add(ll k,ll x,ll N){
    //k += N;
    tree[k] += x;
    for(k = k/2;k>=1;k = k/2){
        tree[k] = tree[2*k] + tree[2*k+1];
    }
}

void solve(){
    ll N,Q;
    cin >> N >> Q;
    ll a[N];
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    memset(tree,0,sizeof(tree));
    
    // for(ll i=0;i<=2*N;i++){
    //     tree[i] = INT_MAX;
    // }
    for(ll i=0;i<N;i++){
        add(i+N,a[i],N);
    }
    // for(ll i=0;i<=2*N;i++){
    //     cout << tree[i] << " \n"[i==2*N];
    // }
    while(Q--){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            c = c-tree[b-1+N];
            add(b-1+N,c,N);
        }
        else if(a == 2){
            cout << sumq(b-1,c-1,N) << endl;
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