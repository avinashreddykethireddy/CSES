#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long


int main(){
    //IOS;
    ll N;
    cin >> N;
    ll a[N];
    
    for(ll i=0;i<N;i++){
        cin >> a[i];
    }
    vector<ll> v;
    v.push_back(a[0]);
    ll b[N];
    memset(b,-1,sizeof(b));
    b[0] = 0;
    ll count=0;
    for(ll i=1;i<N;i++){
        ll flag=-1;
        ll mini=INT_MAX;
        // for(ll j=0;j<v.size();j++){
        //     if(v[j] > a[i]){
        //         // v[j] = a[i];
        //         // b[i] = j;
        //         // flag = 1;
        //         ll temp = mini;
        //         mini = min(mini,v[j]-a[i]);
        //         if(temp != mini){
        //             flag = j;
        //         }
        //     }
        // }
        auto it = upper_bound(v.begin(),v.end(),a[i]);
        flag = it-v.begin();
        //cout << "dwd " << flag << " dw " << v.size() << endl;
        if(flag == v.size()){
            count++;
            v.push_back(a[i]);
            b[i] = count;
        }
        else{
            v[flag] = a[i];
            b[i] = flag;
        }
        //cout << b[i] << " ";
    }
    cout << count+1 << endl;
    

    return 0;
}