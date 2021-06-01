#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long


int main(){
    IOS;
    string s;
    cin >> s;
    ll n = s.size();

    ll a[26] = {0};
    for(int i=0;i<n;i++){
        a[s[i]-'A']++;
    }
    ll odd=0;
    for(int i=0;i<26;i++){
        if(a[i]%2 == 1){
            odd++;
        }
    }
    if(odd >= 2){
        cout << "NO SOLUTION\n";
    }
    else if(odd == 1){
        string ans = "";

        for(int i=0;i<26;i++){
            if(a[i]%2 == 0){
                char ch = (char)(65+i);
                for(int j=0;j<a[i]/2;j++){
                    ans += ch;
                    //cout << ch << endl;
                }
                a[i] = a[i]/2;
            }
            else{
                odd = i;
            }
        }
        char ch = (char)(65+odd);
        for(int j=0;j<a[odd];j++){
            ans += ch;
        }
        a[odd] = 0;
        for(int i=25;i>=0;i--){
            if(a[i] >= 1){
                char ch = (char)(65+i);
                for(int j=0;j<a[i];j++){
                    ans += ch;
                }
                a[i] = 0;
            }
            else{
                odd = i;
            }
        }
        
        cout << ans << endl;

    }
    else{
        string ans = "";
        for(int i=0;i<26;i++){
            if(a[i]%2 == 0){
                char ch = (char)(65+i);
                for(int j=0;j<a[i]/2;j++){
                    ans += ch;
                }
                a[i] = a[i]/2;
            }
            else{
                odd = i;
            }
        }
        for(int i=25;i>=0;i--){
            if(a[i] >= 1){
                char ch = (char)(65+i);
                for(int j=0;j<a[i];j++){
                    ans += ch;
                }
                a[i] = 0;
            }
            else{
                odd = i;
            }
        }
        cout << ans << endl;
    }

    return 0;
}