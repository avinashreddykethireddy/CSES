#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

ll binarySearch(ll arr[],ll l,ll r,ll x){
    if(r >= l){
        ll mid = l + (r-l)/2;
        if(arr[mid] == x){
            return mid;
        }
        if(arr[mid] > x){
            return binarySearch(arr,l,mid-1,x);
        }
        return binarySearch(arr,mid+1,r,x);
    }
    return -1;
}

int main(){
    IOS;
    ll N,X;
    cin >> N >> X;
    ll a[N],b[N];
    for(ll i=0;i<N;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    map<ll,ll> mp;
    ll flag=0;
    for(ll i=0;i<N;i++){
        if(mp.count(X-a[i])){
            flag=1;
            cout << i+1 << " " << mp[X-a[i]] << endl;
            break; 
        }
        mp[a[i]] = i+1;
    }
    if(!flag){
        cout << "IMPOSSIBLE\n";
    }
    // sort(a,a+N);
    // ll index1,index2;
    // index1 = index2 = -1;
    // for(ll i=0;i<N;i++){
    //     index2 = binarySearch(a,0,N-1,X-a[i]);

    //     if(index2 != -1){
    //         index1 = i;
    //         break;
    //     }
    // }
    // //cout << index1 << " " << index2 << endl;

    // for(ll i=0;i<N;i++){
    //     if(a[index1] == b[i]){
    //         index1 = i;
    //         break;
    //     }
    // }
    //       //  cout << index1 << " " << index2 << endl;

    // for(ll i=N-1;i>=0;i--){
    //     if(a[index2] == b[i]){
    //         index2 = i;
    //         break;
    //     }
    // }
    // if(index1 == index2 ){
    //     cout << "IMPOSSIBLE\n";
    // }
    // else{
    //     cout << index1+1 << " " << index2+1 << endl;
    // }

    return 0;
}