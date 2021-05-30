#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){

    ll N;
    cin >> N;
    ll a[N];
    for(int i=0;i<N-1;i++){
        cin >> a[i];
    }
    sort(a,a+N-1);
    int flag = 0;
    for(ll i=1;i<=N-1;i++){
        if(a[i-1] != i){
            cout << i << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << N << endl;
    }

    return 0;
}