#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

vector<ll> adj[100001];
ll visited[100001];
ll dist[100001];


void dfs(ll s){
    
    if(visited[s]) return;

    visited[s] = 1;
    for(auto u : adj[s]){
        
        if(!visited[u]){
            dfs(u);   
        }
        dist[s] = (dist[s] + dist[u])%mod;
        
    }
    
}


void solve(){
    ll N,M;
    cin >> N >> M;
    for(ll i=0;i<M;i++){
        ll u,v;
        cin >> u >> v;
        //adj2[u].push_back(v);
        adj[v].push_back(u);
        //adj[v].push_back(u);
    }
    memset(visited,0,sizeof(visited));
    memset(dist,0,sizeof(dist));
    dist[1] = 1;
    dfs(N);
    
    cout << dist[N] << endl;


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