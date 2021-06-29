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
    ll N;
    cin >> N;
    ll M = N*(N+1)/2;
    if(M%2 == 1){
        cout << "0\n";
        return;
    }
    M = M/2;
    ll dp[N+1][M+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(ll i=1;i<N;i++){
        for(ll j=0;j<=M;j++){
            dp[i][j] = dp[i-1][j];
            if(j-i >= 0){
                dp[i][j] =  (dp[i][j] +dp[i-1][j-i])%mod;
            }
            //cout << dp[i][j] << " \n"[j==M];

        }
    }
    cout << dp[N-1][M] << endl;


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