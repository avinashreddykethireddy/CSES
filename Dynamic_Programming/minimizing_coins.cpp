#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

ll dp[1000001];

void solve(){
    ll N,M;
    cin >> N >> M;
    ll a[N];
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    dp[0] = 0;
    for(ll i=1;i<=M;i++){
        dp[i]=INT_MAX;
        
        for(ll j=0;j<N;j++){
            if(i-a[j] >= 0){
                dp[i] = min(dp[i],dp[i-a[j]]+1);        
            }
        }
        
    }
    if(dp[M] == INT_MAX){
        dp[M] = -1;
    }

    cout << dp[M] << endl;

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