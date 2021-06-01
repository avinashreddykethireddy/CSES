#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){

    ll n;
    cin >> n;
    while(1){
        cout << n << " ";
        if(n == 1){
            break;
        }
        if(n%2 == 0){
            n = n/2;
        }
        else if(n%2 == 1){
            n = n*3 + 1;
        }
    }
    cout << endl;


    return 0;
}