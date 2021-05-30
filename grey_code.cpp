#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long

int main(){
    

    ll N;
    cin >> N;
    ll M = 1 << N;
    string s[M];
    int flag = 0;
    for(int i=1;i<=M;i++){
        if(flag){
            s[i-1]+="1";
        }
        else{
            s[i-1]+="0";
        }
        if(i == M/2){
            flag = 1-flag;    
        }
    }
    flag = 0;
    for(int i=N-1;i>=1;i--){
        int code = 1 << i;
        int first = code/2;
        int fc=0;
        //cout << code << endl;
        for(int j=0;j<M;j++){
            if(fc == first){
                first = -1;
                fc = 0;
                flag = 1;
            }
            else if(fc == code){
                flag = 1-flag;
                fc = 0;
            }
            if(flag){
                s[j]+="1";
            }
            else{
                s[j]+="0";
            }
            fc++;
        }
    }
    for(int i=0;i<M;i++){
        cout << s[i] << endl;
    }
    
    return 0;
}