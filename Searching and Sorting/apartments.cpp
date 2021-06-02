#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    IOS;

    ll N,M,K;
    cin >> N >> M >> K;
    ll a[N],b[M];
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    for(ll i=0;i<M;i++){
        cin >> b[i];
    }
    sort(a,a+N);
    sort(b,b+M);
    ll j=0;
    ll ans=0;
    for(ll i=0;i<N;i++){
        if(j == M){
            break;
        }
        if(a[i]-K <= b[j] && a[i]+K >= b[j]){
            j++;
            ans++;
        }
        else if(a[i]-K > b[j] && a[i]+K > b[j]){
            j++;
            i--;
        }


    }
    cout << ans << endl;

    return 0;
}