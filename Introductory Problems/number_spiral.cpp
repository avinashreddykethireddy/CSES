#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

void solve(){
    ll y,x;
    cin >> y >> x;
    ll k = max(y,x);
    ll mid = 1+k*(k-1);
    ll m_l,m_r;
    
    ll ans=0;
    if(k%2 == 0){
        m_l = mid+k; // k = 4 mid = 13 m_l = 17 
        m_r = mid-k; // m_r = 9
        if(k == y && k == x){
            ans = mid; 
        }
        else if(k == y){
            ans = m_l - x;
        }
        else{
            ans = m_r + y;
        }
    }
    else{
        m_l = mid-k;
        m_r = mid+k;
        if(k == y && k == x){
            ans = mid; 
        }
        else if(k == y){
            ans = m_l + x;
        }
        else{
            ans = m_r - y;
        }
    }
    cout << ans << endl;

}

int main(){

    ll T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}