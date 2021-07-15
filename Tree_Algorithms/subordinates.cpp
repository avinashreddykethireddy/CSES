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

void dfs(ll s){
    if(visited[s]) return; 
    visited[s] = 1;
    dist[s] = 1;
    //cout << s << endl;
    for(auto u : adj[s]){
        dfs(u);   
        dist[s]+=dist[u];
    }
}



void solve(){
    ll N;
    cin >> N;
    for(ll i=2;i<=N;i++){
        ll aa;
        cin >> aa;
        adj[aa].push_back(i);
        //adj[i].push_back(aa);
    }
    memset(dist,0,sizeof(dist));
    //dist[1] = 1;
    dfs(1);
    for(ll i=1;i<=N;i++){
        cout << dist[i]-1 << " \n"[i==N];
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