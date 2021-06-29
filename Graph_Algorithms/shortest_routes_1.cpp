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

const ll INF = (ll)1e9;

vector<pair<ll,ll>> adj[100001];
ll visited[100001];
ll distances[100001];
vector<ll> p;

void dijkstra(ll s) {
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    q.push({0,s});
    distances[s] = 0;
    while(!q.empty()){
        pair<ll,ll> p = q.top();
        q.pop();
        ll d = p.first;
        ll node = p.second;
        if(visited[node] != -1){
            continue;
        }
        visited[node] = 1;
        for(auto tt : adj[node]){
            if(visited[tt.second] != -1){
                continue;
            }
            if(distances[tt.second] == -1 || distances[tt.second] > d + tt.first){
                distances[tt.second] = d+tt.first;
                q.push({d+tt.first,tt.second});
            }
        }
    }
    
}

void solve(){
    ll N,M;
    cin >> N >> M;
    for(ll i=0;i<M;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        //adj[v].push_back({w,u});
    }
    memset(visited,-1,sizeof(visited));
    // for(ll i=0;i<=N;i++){
    //     distances[i] = INT_MAX;
    // }
    memset(distances,-1,sizeof(distances));
    
    dijkstra(1,N);
    for(ll i=1;i<=N;i++){
        cout << distances[i] << " \n"[i==N];
    }


}

signed main(){
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