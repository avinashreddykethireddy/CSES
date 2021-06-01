#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    IOS;

    ll N;
    cin >> N;
    ll count=0;
    ll i=5;
    while(1){
        ll a = N/i;
        if(a == 0){
            break;
        }
        count += a;
        i = i*5;
    }
    cout << count << endl;
    return 0;
}