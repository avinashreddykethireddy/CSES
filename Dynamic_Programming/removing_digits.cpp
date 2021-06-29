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
    for(ll i=0;i<=9;i++){
        dp[i] = 1;
    }
    for(ll i=10;i<=N;i++){
        ll maxi=0;
        ll j=i;
        while(j > 0){
            ll num = j%10;
            j = j/10;
            maxi=max(num,maxi);
        }
        dp[i] = dp[i-maxi] + 1;
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