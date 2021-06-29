#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    //IOS;
    ll N;
    cin >> N;
    ll a[N];
    ll ans = 1;
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    map<ll,ll> mp;
    mp[a[0]] = 0;
    ll j=0;
    queue<ll> q;
    q.push(a[0]);
    for(ll i=1;i<N;i++){
        
        if(mp.find(a[i]) == mp.end()){
            mp[a[i]] = i;
            q.push(a[i]);
        }
        else{
            j = mp[a[i]]+1;
            q.push(a[i]);
            mp[a[i]] = i;
            while(1){

                if(q.front() == a[i]){
                    q.pop();
                    break;
                }
                ll c = q.front();
                q.pop();
                mp.erase(c);
            }

        }
        ans = max(ans,i-j+1);
    }
    cout << ans << endl;

    

    return 0;
}