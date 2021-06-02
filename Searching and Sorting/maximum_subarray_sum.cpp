#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long


int main(){
    IOS;
    ll N;
    cin >> N;
    ll a[N];
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }

    ll max_sum=INT_MIN;
    ll sum=0;
    for(ll i=0;i<N;i++){
        sum += a[i];
        max_sum = max(max_sum,sum);
        if(sum <= 0){
            sum = 0;
        }
    }
    cout << max_sum << endl;

    return 0;
}