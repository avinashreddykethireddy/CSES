#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    IOS;

    ll N;
    cin >> N;
    vector<ll> a1,a2;
    ll sum1=0;
    ll sum2=0;
    for(int i=N;i>=1;i--){
        if(sum1 <= sum2){
            sum1+=i;
            a1.push_back(i);
        }
        else{
            sum2+=i;
            a2.push_back(i);
        }
    }
    if(sum1 != sum2){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << a1.size() << endl;
    for(auto it : a1){
        cout << it << " ";
    }
    cout << endl;
    
    cout << a2.size() << endl;
    for(auto it : a2){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}