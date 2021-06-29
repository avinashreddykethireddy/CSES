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
    string s[N];
    for(ll i=0;i<N;i++){
        cin >> s[i];
    }
    ll dp[N+1][N+1];
    memset(dp,0,sizeof(dp));

    for(ll i=0;i<=N;i++){
        dp[0][i] = -1;    
    }
    for(ll i=0;i<=N;i++){
        dp[i][0] = -1;    
    }
    if(s[0][0] == '.'){
        dp[1][1] = 1;
    }
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++){
            if(s[i-1][j-1] == '*'){
                dp[i][j] = -1;
            }
            else{
                dp[i][j] = (dp[i][j] + (dp[i-1][j] == -1 ? 0 : dp[i-1][j]) + (dp[i][j-1] == -1 ? 0 : dp[i][j-1]))%mod;
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    if(dp[N][N] == -1){
        dp[N][N] = 0;
    }

    cout << dp[N][N] << endl;

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