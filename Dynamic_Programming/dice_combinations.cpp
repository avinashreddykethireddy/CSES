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
    //ll dp[N+1];
    dp[0] = 1;
    for(ll i=1;i<=N;i++){
        dp[i] = 0;
        for(ll j=1;j<=6;j++){
            if(i-j >= 0){
                
                dp[i] = (dp[i]+dp[i-j])%mod;
            }
        }
        
        //cout << i << " " << dp[i] << endl;
         //cout << i << " " << dp[i] << " \n"[i == N];
    }
    cout << dp[N] << endl;


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