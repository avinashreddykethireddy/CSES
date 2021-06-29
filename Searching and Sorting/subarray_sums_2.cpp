#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long


int main(){
    IOS;
    ll N,X;
    cin >> N >> X;
    ll a[N];
    
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    queue<ll> q;
    ll sum=0;
    ll count=0;
    ll prev=0;
    for(ll i=0;i<N;i++){
        q.push(a[i]);
        sum += a[i];

        while(!q.empty()){
            
            if(sum == X){
                count++;
                break;
            }
            else if(sum < X){
                break;
            }
            else if(sum > X){
                sum -= q.front();
                prev = q.front();
                q.pop();
            }
        }
    }
    cout << count << endl;
    

    return 0;
}