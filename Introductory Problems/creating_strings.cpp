#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

vector<string> vs;
void solve(string s,ll l,ll r){
    if(l == r){
        vs.push_back(s);
    }
    else{
        for(ll i=l;i<=r;i++){
            swap(s[l],s[i]);
            solve(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}


int main(){
    string s;
    cin >> s;
    ll N = s.size();
    
    solve(s,0,N-1);
    set<string> ss;
    for(int i=0;i<vs.size();i++){
        ss.insert(vs[i]);
    }
    cout << ss.size() << endl;
    for(auto it : ss){
        cout << it << endl;
    }

    return 0;
}