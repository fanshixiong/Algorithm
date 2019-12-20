#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    string str[] = {"twone", "two", "one"};
    vector<int> ans;
    for(auto a:str){ 
        int pos = 0;
        while((pos=s.find(a, pos)) != string::npos){ //error: pos = s.find(a)
            s[pos+a.length()/2] ='5';
            ans.push_back(pos+a.length()/2);
        }
    }
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] +1 << " ";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}