#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long


int main(){
    IOS;
    ll N;
    cin >> N;
    ll a[N];
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    sort(a,a+N);
    ll ans = 1;
    for(ll i=0;i<N && ans >= a[i] ;i++){
        ans += a[i];
    }
    cout << ans << endl;

    return 0;
}