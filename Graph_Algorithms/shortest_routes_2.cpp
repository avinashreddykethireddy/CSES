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

const ll INF = (ll)1e18;

ll adj[501][501];
ll dist[501][501];

void floyd_warshall(ll N){
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++){
            if(i == j){
                dist[i][j] = 0;
            } 
            else if(adj[i][j]){
                dist[i][j] = adj[i][j];
            }
            else{
                dist[i][j] = INF;
            }
        }
    }
    // cout << "dw" << endl;
    
    for(ll k=1;k<=N;k++){
        for(ll i=1;i<=N;i++){
            for(ll j=1;j<=N;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}


void solve(){
    ll N,M,Q;
    cin >> N >> M >> Q;
    memset(adj,0,sizeof(adj));

    for(ll i=0;i<M;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        
        if(adj[u][v] == 0){
            adj[u][v] = w;
            adj[v][u] = w;
        } 
        else{
            adj[u][v] = min(adj[u][v],w);
            adj[v][u] = min(adj[v][u],w);
        }
        // adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
        
    }
    //memset(visited,-1,sizeof(visited));
    memset(dist,-1,sizeof(dist));
    
    floyd_warshall(N);
    while(Q--){
        ll a,b;
        cin >> a >> b;
        cout << (dist[a][b] == INF ? -1 : dist[a][b])  << endl;
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