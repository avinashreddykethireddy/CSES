#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    ll N;
    cin >> N;
    ll X[N];
    ll count=0;
    for(int i=0;i<N;i++){
        cin >> X[i];
    }
    for(int i=1;i<N;i++){
        if(X[i] < X[i-1]){
            count += (X[i-1]-X[i]);
            X[i] = X[i-1];
        }
    }
    cout << count << endl;

    return 0;
}