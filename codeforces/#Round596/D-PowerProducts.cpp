#include<bits/stdc++.h>
#define ll long long

using namespace std;

map<vector<pair<int, int> >, int> M;
int main(){
    int n, k, x;
    ll ans=0;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        vector<pair<int, int> > v1, v2;
        cin >> x;
        for(int j=2; j*j<=x; j++){
            if(x%j) continue;
            int cnt=0;
            while(x%j==0){
                x/=j;
                cnt++;
            }
            if(cnt%k) 
                v1.push_back({j, cnt%k});
        }
        if(x>1)
            v1.push_back({x, 1});
        for(int j=0; j<v1.size(); j++)
            v2.push_back({v1[j].first, k-v1[j].second});
        ans += M[v2];
        M[v1]++;
    }
    cout << ans << endl;
    return 0;
}