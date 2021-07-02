#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892


// dijkstra 
vector<pair<ll,ll>> adj[100001];
vector<pair<ll,ll>> adj2[100001];
ll visited[100001];
ll distances[100001];
vector<ll> p;

vector<ll> ans1;
vector<ll> ans2;

void dijkstra_sum(ll s,ll N) {
    memset(visited,-1,sizeof(visited));
    memset(distances,-1,sizeof(distances));
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
            if(visited[tt.first] != -1){
                continue;
            }
            if(distances[tt.first] == -1 || distances[tt.first] > d + tt.second){
                distances[tt.first] = d+tt.second;
                q.push({d+tt.second,tt.first});
            }
        }
    }
    while(!q.empty()){
        q.pop();
    }

    for(ll i=1;i<=N;i++){
        ans1.push_back(distances[i]);
        
         //cout << distances[i] << " \n"[i==N];
    }
    s = N;
    memset(visited,-1,sizeof(visited));
    memset(distances,-1,sizeof(distances));
    //q.clear();
    //priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
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
        for(auto tt : adj2[node]){
            if(visited[tt.first] != -1){
                continue;
            }
            if(distances[tt.first] == -1 || distances[tt.first] > d + tt.second){
                distances[tt.first] = d+tt.second;
                q.push({d+tt.second,tt.first});
            }
        }
    }
    for(ll i=1;i<=N;i++){
        ans2.push_back(distances[i]);
        //cout << distances[i] << " \n"[i==N];
    }
    ll cost = ans1[N-1];
    for(ll i=1;i<=N;i++){
        for(auto it : adj[i]){
            cost = min(cost,ans1[i-1]+ans2[it.first-1]+it.second/2);
        }
    }
    cout << cost << endl;



    
}

void solve(){
    ll N,M;
    cin >> N >> M;
    for(ll i=0;i<M;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj2[v].push_back({u,w});
    }
    memset(visited,0,sizeof(visited));
    memset(distances,0,sizeof(distances));
    dijkstra_sum(1,N);



    

    
    



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