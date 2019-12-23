#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int main(){
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    t=s;
    for(int i=0; i<n; i++){
        t[i] = s[i%m];
    }
    //cout << t << endl;
    if(t>=s){
        cout << t.length() << endl;
        cout << t << endl;
        return 0;
    }
    for(int i=m-1; i>=0; i--){
        if(t[i] != '9'){
            t[i]++;
            for(int j=i+1; j<m; j++){
                t[j] = '0';
            }
            break;
        }
    }
    cout << n << endl;
    for(int i=0; i<n; i++)
        cout << t[i%m];
    return 0;
}