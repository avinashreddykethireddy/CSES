#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long


int main(){
    IOS;
    ll X,N;
    cin >> X >>  N;
    ll a[N];
    
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    set<ll> s;
    s.insert(0);
    s.insert(X);
    for(ll i=0;i<N;i++){
        s.insert(a[i]);
    }
    ll ans = INT_MIN;
    ll prev1;
    for(auto it=s.begin();it != s.end();it++){
        if(it == s.begin()){
            prev1 = *it;
        }
        else{
            ans = max(ans,*it-prev1);
            prev1 = *it;
        }
    }
    vector<ll> v;
    for(ll i=N-1;i>=0;i--){
        v.push_back(ans);
        auto it = s.find(a[i]);
        auto it1 = next(it);
        auto it2 = prev(it);
        if(abs(*it1-*it2) >= ans){
            ans = abs(*it1-*it2);
            
        }
        s.erase(a[i]);
    }
    for(ll i=v.size()-1;i>=0;i--){
        cout << v[i] << " ";
    }
    
    

    return 0;
}