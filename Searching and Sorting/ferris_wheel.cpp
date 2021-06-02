#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    IOS;

    ll N,X;
    cin >> N >> X;
    ll p[N];
    
    for(ll i=0;i<N;i++){
        cin >> p[i];
    }
    sort(p,p+N);
    ll ans=0,j=0;
    for(ll i=N-1;i>=0;i--){
        if(p[i] == INT_MAX){
            continue;
        }
        ll xx = X-p[i];
        if(p[j] <= xx){
            p[j] = INT_MAX;
            j++;
        }
        p[i] = INT_MAX;
        ans++;
    }
    cout << ans << endl;



    return 0;
}