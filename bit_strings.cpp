#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    IOS;

    ll N;
    cin >> N;
    ll count=1;
    for(int i=1;i<=N;i++){
        count = (count*2)%(1000000007);
    }
    cout << count << endl;
    return 0;
}