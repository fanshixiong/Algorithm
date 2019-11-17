#include<bits/stdc++.h>
using namespace std;
int a, b, n, s;
int main(){
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--){
        cin >> a >> b >> n >> s;
        int t = s/n;
        if((a>=t && b>=s-t*n)|| (b>=s)){
            cout << "YES" << endl;
        }
        else if(t>=a && s-a*n<=b)
            cout << "YES" << endl;
        else{
            cout << "NO" <<endl;
        }
        
    }
    return 0;
}