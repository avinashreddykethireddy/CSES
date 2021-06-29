#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

//ll dp[100001][1000];

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int&v : price) cin >> v;
    for (int&v : pages) cin >> v;
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-price[i-1];
            if (left >= 0) {
	            dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
            }
        }
    }
    cout << dp[n][x] << endl;
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