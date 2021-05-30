#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    ll N;
    cin >> N;
    ll P[N];
    ll sum=0;
    for(int i=0;i<N;i++){
        cin >> P[i];
        sum += P[i];
    }
    ll a=0,b=0;
    ll pp = 1 << N;
    ll ans=INT_MAX;
    for(ll i=1;i<pp;i++){
        a=0;
        for(ll j=0;j<N;j++){
            if( i & (1 << j) ){
                a+=P[j];
            }
        }
        b = sum-a;
        ans = min(ans,abs(b-a));

    }
    cout << ans << endl;

    return 0;
}