#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

//ll dp[100001][100];

void solve(){
    int N,X=0;
    cin >> N;
    ll W[N+1];
    for(ll i=1;i<=N;i++){
        cin >> W[i];
        X+=W[i];
    }
    vector<vector<bool>> dp(X+1,vector<bool>(N+1,0));
    //ll dp[X+1][N+1];
    //memset(dp,0,sizeof(dp));
    dp[0][0] = true;
    for(ll i=0;i<=X;i++){
        for(ll j=1;j<=N;j++){
            dp[i][j] = dp[i][j-1];
            if(i-W[j] >= 0 && dp[i-W[j]][j-1]){
                dp[i][j] = true;
                //dp[i][j] = max(dp[i][j],dp[i-W[j]][j-1]+V[j]);
            }
        }
    }
    vector<ll> ans;
    for(ll i=1;i<=X;i++){
        if(dp[i][N] == 1){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(auto it : ans){
        cout << it << " ";
    }
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