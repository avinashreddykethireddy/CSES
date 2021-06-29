#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long


int main(){
    IOS;
    ll N;
    cin >> N;
    set<ll> s;
    for(ll i=1;i<=N;i++){
        s.insert(i);
    }
    auto it = s.begin();
    while(1){
        it++;
        cout << *it << " ";
        s.erase(it);
        it++;
        if(it == s.end()){
            it = s.begin();
        }
        if(s.empty()){
            break;
        }
    }
    
    

    return 0;
}