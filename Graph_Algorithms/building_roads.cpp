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
void dfs(ll s){
    if(visited[s]) return;
    visited[s] = 1;
    for(auto u : adj[s]){
        dfs(u);
    }
}

// void bfs(ll x){
//     visited[x] = true;
//     distance[x] = 0;
//     q.push(x);
//     while (!q.empty()) {
//         int s = q.front(); q.pop();
//         // process node s
//         for (auto u : adj[s]) {
//             if (visited[u]) continue;
//             visited[u] = true;
//             distance[u] = distance[s]+1;
//             q.push(u);
//         }
//     }
// }

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
    vector<ll> ans;
    for(ll i=1;i<=N;i++){
        if(visited[i] == 0){
            dfs(i);
            ans.push_back(i);
        }
    }

    cout << ans.size()-1 << endl;
    ll a = ans[0];
    for(ll i=1;i<ans.size();i++){
        cout << a << " " << ans[i] << endl;
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