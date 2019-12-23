#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    if(n == 1){
        cout << 9 << " " << 8 << endl;
    }
    else
        cout << n*3 << " " <<n*2 <<endl;
    return 0;
}