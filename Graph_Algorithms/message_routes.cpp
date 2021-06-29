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

ll distances[100001];
ll prevStep[100001];

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
    memset(prevStep,0,sizeof(prevStep));
    prevStep[1] = -1;
    bfs(1);
    if(visited[N]){
        cout << distances[N]+1 << endl;
        vector<ll> ans;
        ans.push_back(N);
        while(prevStep[N] != -1){
            ans.push_back(prevStep[N]);
            //cout << prevStep[N] << " ";
            N = prevStep[N];
        }
        reverse(ans.begin(),ans.end());
        for(auto it : ans){
            cout << it << " ";
        }

    }
    else{
        cout << "IMPOSSIBLE\n";
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