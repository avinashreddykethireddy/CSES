#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

void solve(ll N){
    
    ll n = N*N;
    ll count = n*(n-1)/2; // total number of moves
    count = count - 4*(N-1)*(N-2);
    cout << count << endl;
}

int main(){
    IOS;

    ll N;
    cin >> N;
    ll i=1;
    while(i != N+1){
        solve(i);
        i++;
    }


    return 0;
}