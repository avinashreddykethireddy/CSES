#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long


int main(){
    IOS;
    ll N;
    cin >> N;
    vector<pair<pair<ll,ll>,ll>> v(N);
    for(ll i=0;i<N;i++){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    ll ans[N] = {0};
    priority_queue<pair<ll,ll>> pq;
    ll count=0;
    for(ll i=0;i<N;i++){
        if(pq.empty()){
            count++;
            pq.push({-v[i].first.second,count});
            ans[v[i].second] = count;
        }
        else{
            if(-pq.top().first < v[i].first.first){
                ans[v[i].second] = pq.top().second;
                
                pq.pop();
                pq.push({-v[i].first.second,ans[v[i].second]});
            }
            else{
                count++;
                ans[v[i].second] = count;
                pq.push({-v[i].first.second,count});
            }
        }
    }
    cout << count << endl;
    for(ll i=0;i<N;i++){
        cout << ans[i] << " ";
    }

    return 0;
}