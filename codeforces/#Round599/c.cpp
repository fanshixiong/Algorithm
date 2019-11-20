#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){
    return b==0?a:gcd(b, a%b);  
}
int main(){
    ll n;
    cin >> n;
    ll cnt=n;
    for(ll i=2; i*i <= n; i++){
        if(n%i==0){
            cnt = gcd(cnt, i);
            cnt = gcd(cnt, n/i);
        }
    }
    cout << cnt << endl;
    return 0;
}