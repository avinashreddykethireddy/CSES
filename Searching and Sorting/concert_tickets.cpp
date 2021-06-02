#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    IOS;

    ll N,M;
    cin >> N >> M;
    ll a[N],b[M];
    multiset<ll,greater<ll>> ms;
    for(ll i=0;i<N;i++){
        cin >> a[i];
        ms.insert(a[i]);
    }
    // for(auto it : ms){
    //     cout << it << endl;
    // }
    for(ll i=0;i<M;i++){
        cin >> b[i];
        auto ans = ms.lower_bound(b[i]);
        if(ans == ms.end()){
            cout << "-1\n";
        }
        else{
            ms.erase(ms.find(*ans));
            cout << *ans << endl;    
        }
    
    }

    

    return 0;
}