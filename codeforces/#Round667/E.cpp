#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for(int i=0; i<n; i++){
        int x , y ;
        cin >> x >> y;
        v.push_back({x-y, x+y});
    }
    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)->bool{
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    int end = 0;
    int ans = 0;
    for(auto x : v){
        if(x.second > end){
            ans++;
            end = x.second;
        }
    }
    cout << ans << endl;
    return 0;
}