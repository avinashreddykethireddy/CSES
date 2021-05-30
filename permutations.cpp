#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    ll N;
    cin >> N;
    if(N == 2 || N == 3){
        cout << "NO SOLUTION\n";
    }
    else{
        vector<ll> v;
        for(int i=N;i>=1;i--){
            if(i%2 == 1){
                v.push_back(i);
            }
        }
        for(int i=N;i>=1;i--){
            if(i%2 == 0){
                v.push_back(i);
            }
        }
        for(auto it : v){
            cout << it << " ";
        }
        cout << endl;
    }
    
    return 0;
}