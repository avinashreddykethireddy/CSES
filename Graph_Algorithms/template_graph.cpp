#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

// graph grid probs
ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};
string ds = "RLDU";


vector<ll> adj[100001];
vector<ll> [100001];
ll visited[100001];
ll distances[100001];

// for grid type problems eg labyrinth
// ll visited[1001][1001];
// ll grid[1001][1001];
// ll prevStep[1001][1001];

void dfs(ll s){
    if(visited[s]) return;
    visited[s] = 1;
    for(auto u : adj[s]){
        dfs(u);
    }
}


void bfs(ll x){
    queue<ll> q;
    visited[x] = 1;
    distances[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        // process node s
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = 1;
            distances[u] = distances[s]+1;
            q.push(u);
            prevStep[u] = s;
        }
    }
}


// dijkstra 
// vector<pair<ll,ll>> adj[100001];
// ll visited[100001];
// ll distances[100001];
// vector<ll> p;

void dijkstra(ll s) {
    memset(visited,-1,sizeof(visited));
    memset(distances,-1,sizeof(distances));
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    q.push({0,s});
    distances[s] = 0;
    while(!q.empty()){
        pair<ll,ll> p = q.top();
        q.pop();
        ll d = p.second;
        ll node = p.first;
        if(visited[node] != -1){
            continue;
        }
        visited[node] = 1;
        for(auto tt : adj[node]){
            if(visited[tt.first] != -1){
                continue;
            }
            if(distances[tt.first] == -1 || distances[tt.first] > d + tt.second){
                distances[tt.first] = d+tt.second;
                q.push({d+tt.second,tt.first});
            }
        }
    }
    
}


void bellman_ford(ll x){
    ll distance[N+1];
    for(ll i=0;i<=N;i++){
        distance[i] = INT_MAX;
    }
    distance[x] = 0;
    for(ll i=1;i<=N-1;i++){
        for(auto u : adj[x]){
            ll a,b,w;
            tie(a,b,w) = u;
            distance[b] = min(distance[b],distance[a]+w);
        }
    }
}

void solve(){
    ll N,M;
    cin >> N >> M;
    for(ll i=0;i<M;i++){
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited,0,sizeof(visited));
    memset(distances,0,sizeof(distances));
    


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