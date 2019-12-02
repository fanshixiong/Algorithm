#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, k;
        cin >> a >> b >> k;
        ll t = gcd(a, b);
        if(a == b){
            cout << "OBEY" << endl;
        }
        else{
            if(a > b){
                swap(a, b);
            }
            if( (t + (k-1)*a) < b)
                cout << "REBEL" << endl;
            else
            {
                cout << "OBEY" << endl;
            }
            
        }
    }
    return 0;
}