#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define all(x) begin(x), end(x)
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892
 
// graph grid probs
// ll dx[]={0,0,1,-1};
// ll dy[]={1,-1,0,0};
// string ds = "RLDU";
 
 
vector<ll> adj[100001];
ll visited[100001];
vector<ll> cycle;
ll till=-1;
bool dfs(ll v){
    if(visited[v] != 0) return 0;

    visited[v] = 1;
    for(auto u : adj[v]){
        if(visited[u] == 0){
            ll x = dfs(u);
            if(x != 0){
                if(x == 2){
                    return 2;
                }
                cycle.push_back(v);
                if(v == till){
                    return 2;
                }
                else{
                    return 1;
                }
            }
        }
        else if(visited[u] == 1){
            cycle.push_back(u);
            cycle.push_back(v);
            till = u;
            return 1;
        }
    }
    visited[v] = 2;
    return 0;
}
 
 
void solve(){
    ll N,M;
    cin >> N >> M;
    for(ll i=0;i<M;i++){
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    memset(visited,0,sizeof(visited));

    for(ll i=1;i<=N;i++){
        if(!visited[i]){
            dfs(i);        
        }
        if(cycle.size() > 0){
            break;
        }
    }
    if(cycle.size() == 0){
        cout << "IMPOSSIBLE\n";
    }
    else{
        reverse(all(cycle));
        //cout << cycle.size() << endl;
        ll flag = cycle[cycle.size()-1];
        vector<ll> ans;
        for(auto it : cycle){
            if(flag == it){
                flag = -1;
            }
            if(flag == -1) ans.push_back(it); 
        }
        cout << ans.size() << endl;
        for(auto it : ans){
            cout << it << " ";
        }
        cout << endl;
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