#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef long double ld;
#define mod 1000000007
// string dec_num = "982892";
// ll num = stoll(dec_num,nullptr,10); num = 982892

// void dfs(ll s){
//     if(visited[s]) return;
//     visited[s] = true;
//     for(auto u : adj[s]){
//         dfs(u);
//     }
// }

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

ll flag=0;

ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};
//string ds="UDRL";
string ds = "RLDU";
 
bool possible(ll x,ll y,ll n,ll m){
    return (x<n&&x>=0&&y<m&&y>=0);
}

ll visited[1001][1001];
ll grid[1001][1001];
ll prevStep[1001][1001];
vector<pair<ll,ll>> ans;

void bfs(ll x,ll y,ll N,ll M,pair<ll,ll> a){
    queue<pair<ll,ll>> q;
    visited[x][y] = 1;
    q.push({x,y});
    while(!q.empty()){
        pair<ll,ll> s = q.front();
        x = s.first;
        y = s.second;
        visited[x][y] = 1;
        q.pop();
        for(ll i=0;i<4;i++){
            ll nx = x+dx[i];
            ll ny = y+dy[i];    
            if( !possible(nx,ny,N,M) || visited[nx][ny] == 1 || grid[nx][ny] == 0){
                continue;
            }
            
            visited[nx][ny] = 1;
            q.push({nx,ny});
            prevStep[nx][ny] = i;
        }
    }
    
}

void solve(){
    ll N,M;
    cin >> N >> M;
    string s[N];

    memset(grid,0,sizeof(grid));
    memset(visited,0,sizeof(visited));
    pair<ll,ll> start;
    pair<ll,ll> end;
    
    for(ll i=0;i<N;i++){
        cin >> s[i];
        for(ll j=0;j<M;j++){
            if(s[i][j] == 'A'){
                start = {i,j};
                grid[i][j] = 1;
            }
            if(s[i][j] == 'B'){
                end = {i,j};
                grid[i][j] = 1;
            }
            if(s[i][j] == '.'){
                grid[i][j] = 1;
            }

            if(s[i][j] == '#'){
                grid[i][j] = 0;
            }
        }
    }
    bfs(start.first,start.second,N,M,end);
    

    if(visited[end.first][end.second] == 0){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        vector<char> ans;
        while(end != start){
            ll i = prevStep[end.first][end.second];
            ans.push_back(ds[i]);
            end = {end.first-dx[i],end.second-dy[i]};
        }
        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        for(auto it : ans){
            cout << it ;
        }
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