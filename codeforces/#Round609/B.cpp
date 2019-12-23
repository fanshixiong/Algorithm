#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int a[maxn], b[maxn];
vector<pair<int, int> > cnt_a, cnt_b;
int main(){
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    map<int, int> cnt1, cnt2;
    for(int i=0; i<n; i++){
        cin >> a[i];
        cnt1[a[i]]++;
    }
    for(int i=0; i<n; i++){
        cnt_a.push_back({cnt1[a[i]], a[i]});
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        cnt2[b[i]]++;
    }
    for(int i=0; i<n; i++){
        cnt_b.push_back({cnt2[b[i]], b[i]});
    }
    sort(cnt_a.begin(), cnt_a.end());
    sort(cnt_b.begin(), cnt_b.end());
    int t=cnt_a[0].first, cnt=0;
    for(int i=0; i<n; i++){
        if(cnt_a[i].first == t)
            cnt++;
        else
            break;
    }
    int mina=0x3f3f3f, minb = 0x3f3f3f;
    for(int i=0; i<cnt; i++){
        mina = min(mina, cnt_a[i].second);
        minb = min(minb, cnt_b[i].second);
    }
    int ans1 = abs(mina-minb);
    int ans2 = min(mina, minb)+m - max(mina, minb);
    int tmp1[n+1], tmp2[n+1];
    for(int i=0; i<n; i++){
        tmp1[i] = (a[i]+ans1)%m;
        tmp2[i] = (a[i]+ans2)%m;
    }
    sort(b, b+n);
    sort(tmp1, tmp1+n);
    sort(tmp2, tmp2+n);
    bool flg1=0, flg2=0;
    for(int i=0; i<n; i++){
        if(tmp1[i] != b[i])
            flg1=1;
        if(tmp2[i] != b[i])
            flg2=1;
    }
    if(!flg1)
        cout << ans1 << endl;
    else if(!flg2)
        cout << ans2 << endl;
    else{
        int tmpx[n+1] = {0};
        bool flg=0;
        int ans=b[0]+2-mina;
        for(int x=0; x<m; x++){
            flg=0;
            for(int i=0; i<n; i++){
                tmpx[i] = (a[i]+x)%m;
            }
            sort(tmpx, tmpx+n);
            for(int i=0; i<n; i++){
                if(tmpx[i] != b[i]){
                    flg=1;
                    break;
                }
            }
            if(!flg){
                ans = x;
                break;
            }
            if(flg)
                continue;
        }
        cout << ans << endl;
    }    
    return 0;
}