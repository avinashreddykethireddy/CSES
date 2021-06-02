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
    ll ans=1;
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    sort(a,a+N);
    for(ll i=0;i<N-1;i++){
        if(a[i] != a[i+1]){
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}