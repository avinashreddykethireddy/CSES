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
    string a,b;
    cin >> a >> b;
    ll N = a.size();
    ll M = b.size();
    vector<vector<ll>> dp(N+1,vector<ll>(M+1,1e9));
    dp[0][0] = 0;
    for(ll i=0;i<=N;i++){
        for(ll j=0;j<=M;j++){
            if(i != 0){
                dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
            }   
            if(j != 0){
                dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
            }   
            if(i != 0 && j != 0){
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(a[i-1] != b[j-1]));
            }   
        }
    }
    cout << dp[N][M] << endl;
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