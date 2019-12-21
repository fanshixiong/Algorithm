#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    map<char, char> w;
    w['B'] = 'W';
    w['W'] = 'B';
    for(int i=0; i<n-1; i++){
        if(s[i] != 'W'){
            v.push_back(i+1);
            s[i] = 'W';
            s[i+1] = w[s[i+1]];
        }
    }
    if(s[n-1] != 'W'){
        for(int i=0; i<n-1; i++){
            if(s[i] != 'B'){
                v.push_back(i+1);
                s[i] = 'B';
                s[i+1] = w[s[i+1]];
            }
        }
        if(s[n-1] != 'B'){
            cout<<-1 << endl;
            return 0;
        }
    }
    int ans = v.size();
    cout << ans << endl;
    for(int i=0; i<ans; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}