#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define what_is(x) cerr << #x << " is " << x << endl;
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

// graph grid probs
// ll dx[]={0,0,1,-1};
// ll dy[]={1,-1,0,0};
// string ds = "RLDU";


vector<ll> adj[100001];
ll visited[100001];
ll revisited[100001];

// for grid type problems eg labyrinth
// ll visited[1001][1001];
// ll grid[1001][1001];
// ll prevStep[1001][1001];

vector<ll> ans;
int flag=0;
void dfs(ll s){
    if(visited[s] != 0){
        return ;
    }
    
    visited[s] = 1;
    for(auto u : adj[s]){
        if(visited[u] == 1){
            flag = 1;
        }
        dfs(u);
    }
    visited[s] = 2;
    ans.push_back(s);
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
    // memset(distances,0,sizeof(distances));
    for(ll i=1;i<=N;i++){
        if(visited[i] == 0){
            dfs(i);
        }
    }
    if(flag){
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(ans.begin(),ans.end());

    for(auto it : ans){
        cout << it << " ";
    }
    cout  << endl;
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