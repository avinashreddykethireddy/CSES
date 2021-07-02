#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

// graph grid probs
// ll dx[]={0,0,1,-1};
// ll dy[]={1,-1,0,0};
// string ds = "RLDU";


vector<pair<ll,ll>> adj[100001];

void bellman_ford(ll N){
    
    vector<ll> d(N+1,0);
    vector<ll> p(N+1,-1);
    
    ll neg=-1;
    for(ll j=1;j<=N;j++){
        neg = -1;
        for(ll i=1;i<=N;i++){
            for(auto u : adj[i]){
                // ll a,b,w;
                // tie(a,b,w) = u;
                // distance[b] = min(distance[b],distance[a]+w);
                if(d[i]+u.second < d[u.first] ){
                    d[u.first] = d[i] + u.second;
                    p[u.first] = i;
                    neg = u.first;
                }
            }
        }
    }
    if(neg == -1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for(ll i=1;i<=N;i++){
            neg = p[neg];
        }
        vector<ll> cycle;
        for(ll v=neg;;v=p[v]){
            cycle.push_back(v);
            if(v == neg && cycle.size() > 1){
                break;
            }
        }
        reverse(cycle.begin(),cycle.end());
        for(auto it : cycle){
            cout << it << " "; 
        }
        cout << endl;
    }

}

void solve(){
    ll N,M;
    cin >> N >> M;
    for(ll i=0;i<M;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        //adj[v].push_back({u,w});
    }
    bellman_ford(N);

    


}

int main(){
    IOS;

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    ll T=1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}