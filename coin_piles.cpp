#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

void solve(){
    ll a,b;
    cin >> a >> b;
    ll x,y;
    if((2*b-a)%3 == 0){
        y = (2*b-a)/3;
        x = b-2*y;
        if(y >= 0 && x >= 0){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    IOS;

    ll T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}