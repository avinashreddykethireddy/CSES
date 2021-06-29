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

    stack<pair<ll,ll>> s;
    for(ll i=0;i<N;i++){
        
        while(!s.empty()){
            if(s.top().first < a[i]){
                cout << s.top().second << " ";
                break;
            }
            else{
                s.pop();
            }
        }
        if(s.empty()){
            cout << "0 ";
        }
        
    
        s.push({a[i],i+1});
    }
    
    // for(ll i=0;i<N;i++){
    //     ll flag=0;
    //     for(ll j=i-1;j>=0;j--){
    //         if(a[j] < a[i]){
    //             cout << j+1 << " ";
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(!flag){
    //         cout << "0 ";
    //     }
    // }

    return 0;
}