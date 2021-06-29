#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long


int main(){
    IOS;
    ll N,X;
    cin >> N >> X;
    ll a[N];
    
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    map<ll,ll> mp;
    ll flag=0;
    for(ll i=0;i<N;i++){
        for(ll j=i+1;j<N;j++){
            if(mp.count(X-a[i]-a[j])){
                cout << i+1 << " " << j+1 << " " << mp[X-a[i]-a[j]] << endl;
                flag = 1;
                break;
            }
            mp[a[j]] = j+1;
        }
        mp[a[i]] = i+1;
        
        if(flag){
            break;
        }
    }
    if(flag == 0){
        cout << "IMPOSSIBLE\n";
    }
    

    return 0;
}