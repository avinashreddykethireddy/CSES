#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define what_is(x) cerr << #x << " is " << x << endl;
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

vector<ll> adj[200001];
ll visited[200001];
ll dist[200001];
ll succ[200001][32];

ll dfs(ll s,ll d,ll k){
    // if(visited[s]) return -1;
    // visited[s] = 1;
    d++;
    if(d == k){
        return s;
    }
    for(auto u : adj[s]){
        //if(!visited[u]){
        ll x = dfs(u,d,k);   
        //}
        if(x != -1){
            return x;
        }
        if(d == k){
            return u;
        }
    }
    return -1;
}

void precalculate(ll N){
    for(ll i=0;i<=31;i++){
        ll x = 1 << i;
        cout << x << endl;
        for(ll j=1;j<=N;j++){
            succ[j][i] = dfs(j,0,x);
            what_is(j);
            what_is(i);
            what_is(x);
            what_is(succ[j][i]);
        }
    }
}


void solve(){
    ll N,Q;
    cin >> N >> Q;
    for(ll i=1;i<=N;i++){
        ll u;
        cin >> u;
        //adj2[u].push_back(v);
        adj[i].push_back(u);
        //adj[v].push_back(u);
    }
    // memset(visited,0,sizeof(visited));
    // memset(dist,0,sizeof(dist));
    memset(succ,0,sizeof(succ));
    precalculate(N);
    while(Q--){
        ll a,b;
        cin >> a >> b;
        
    }
    

}

int main(){
    //IOS;

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    ll T=1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}