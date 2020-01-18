#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+7;
int n;
int solve(vector<int> a, int pos){
    if(a.size() == 0 || pos < 0)
        return 0;
    vector<int> p1, p2;
    for (int i = 0; i < a.size(); i++){
        if((a[i]>>pos) & 1){
            p1.push_back(a[i]);
        }
        else{
            p2.push_back(a[i]);
        }
    }
    if(p1.size() == 0){
        return solve(p2, pos - 1);
    }
    if(p2.size() == 0){
        return solve(p1, pos - 1);
    }
    return (1 << pos) + min(solve(p1, pos - 1), solve(p2, pos - 1));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    vector<int> a;
    for (int i = 0; i<n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    int ans = solve(a, 30);
    cout << ans << endl;
    return 0;
}