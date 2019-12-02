#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int n, m, k, t;
int a[maxn], l[maxn], r[maxn], d[maxn];
bool judge(int x){
    int rem = 0;
    vector<pair<int, int> > va;
    int minx = 1e9;
    for(int i=0; i<x; i++)
        minx = min(minx, a[i]);
    for(int i=0; i<k; i++){
        if(d[i] > minx){
            va.push_back(make_pair(l[i], r[i]));
        }
    }
    int pos = 0;
    sort(va.begin(), va.end());
    for(int i=0; i<va.size(); i++){
        if(va[i].first <= pos){
            rem += max(va[i].second-pos, 0);
            pos = max(va[i].second, pos);
        }
        else{
        // ①   rem += va[i].second-pos+1; 
            rem += va[i].second - va[i].first + 1; // ②
            //difference : ① is without squad and ② is with squad;
            pos = va[i].second;
        }
    }
    rem = 2 * rem + 1 + n;
    return rem <= t;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> m >> n >> k >> t;
    for(int i=0; i<m; i++)
        cin >> a[i];
    sort(a, a+m);
    reverse(a, a+m);
    for(int i=0; i<k; i++){
        cin >> l[i] >> r[i] >> d[i];
    }
    int left = 0, right = m+1;
    while(1 < right-left){
        int mid = (left + right)/2;
        if(judge(mid)){
            left = mid;
        }
        else{
            right = mid;
        }
        
    }
    cout << left << endl;
    return 0;
}