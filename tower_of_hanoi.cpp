#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

void solve(ll N,ll A,ll B, ll C){
    if(N > 0) {
        solve(N-1,A,C,B);
        cout << A << " " << C << endl;
        solve(N-1,B,A,C);
    }

}

int main(){
    

    ll N;
    cin >> N;
    ll M = 1 << N;
    cout << M-1 << endl;
    solve(N,1,2,3);
    return 0;
}