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

ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};
 
bool possible(ll x,ll y,ll n,ll m){
    return (x<n&&x>=0&&y<m&&y>=0);
}

ll visited[1001][1001];
ll grid[1001][1001];
    
void dfs(ll x,ll y,ll N,ll M){
    if(!possible(x,y,N,M) || visited[x][y] == 1 || grid[x][y] == -1){
        return;
    }
    visited[x][y] = 1;
    for(ll i=0;i<4;i++){
        ll nx = x+dx[i];
        ll ny = y+dy[i];
        dfs(nx,ny,N,M);
    }
}


void solve(){
    ll N,M;
    cin >> N >> M;
    string s[N];

    memset(grid,0,sizeof(grid));
    memset(visited,0,sizeof(visited));

    for(ll i=0;i<N;i++){
        cin >> s[i];
        for(ll j=0;j<M;j++){
            if(s[i][j] == '.'){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = -1;
            }
        }
    }

    ll count=0;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<M;j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                dfs(i,j,N,M);
                count++;
            }
        }
    }
    cout << count << endl;



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