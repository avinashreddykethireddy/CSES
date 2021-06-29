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


vector<ll> adj[100001];
ll visited[100001];

// void dfs(ll s){
//     if(visited[s]) return;
//     visited[s] = 1;
//     for(auto u : adj[s]){
//         dfs(u);
//     }
// }
int flag = 0;
ll colors[100001];
void bfs(ll x){
    queue<ll> q;
    visited[x] = 1;
    colors[x] = 1;
    q.push(x);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        // process node s
        for (auto u : adj[s]) {
            //if (visited[u]) continue; // for bipartite don't need visited
            visited[u] = 1;
            if(colors[u] == -1){
                colors[u] = 1-colors[s];
                q.push(u);
            }
            else if(colors[u] == colors[s]){
                flag = 1;
            }
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
    memset(colors,-1,sizeof(colors));
    for(ll i=1;i<=N;i++){
        if(!visited[i]){
            bfs(i);
        }
    }
    if(flag){
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(ll i=1;i<=N;i++){
        cout << colors[i]+1 << " \n"[i == N];
    }
 
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