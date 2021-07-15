

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define all(x) begin(x),end(x)

// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

ll a[1001][1001];

void solve(){
    ll N,Q;
    cin >> N >> Q;
    memset(a,0,sizeof(a));
    // string s[N][N];
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++){
            // cin >> s[i][j];
            char ch;
            cin >> ch;
            if(ch == '*'){
                a[i][j] = 1;
            }
        }
    }
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++){
            a[i][j] += a[i][j-1];
        }
    }
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++){
            a[j][i] += a[j-1][i];
        }
    }
    // for(ll i=1;i<=N;i++){
    //     for(ll j=1;j<=N;j++){
    //         cout << a[i][j] << " \n"[j==N];
    //     }
    // }
    


    while(Q--){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = a[x2][y2]-a[x1-1][y2]-a[x2][y1-1] + a[x1-1][y1-1];
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