#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    string s;
    cin >> s;
    ll count=1;
    ll N = s.size();
    ll maxi=1;
    
    for(int i=0;i<N-1;i++){
        if(s[i] == s[i+1]){
            count++;
        }
        else{
            count = 1;
        }
        maxi = max(maxi,count);

        
    }
    cout << maxi << endl;

    return 0;
}