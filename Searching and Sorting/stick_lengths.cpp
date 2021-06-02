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
    ll mid;
    if(N%2 == 0){
        mid = a[N/2];
    }
    else{
        mid = (a[N/2]+a[N/2+1])/2;
    }
    ll ans=0;
    for(ll i=0;i<N;i++){
        ans += abs(mid-a[i]);
    }
    cout << ans << endl;

    return 0;
}