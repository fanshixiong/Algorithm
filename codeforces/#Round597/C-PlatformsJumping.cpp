#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n, m, d;
    cin >> n >> m >> d;
    int step[1010], ans[1010];
    memset(ans, 0, sizeof(ans));
    int sum=0, pos=0;
    for(int i=0; i<m; i++){
        cin >> step[i];
        pos += (d+step[i]-1);
    }
    pos += d;
    if(pos < n+1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    pos = 0;
    for(int i=0; i<m; i++)
        sum += step[i];
    for(int i=0; i<m; i++){
        if(pos+sum-1+d<=n)
            pos+=d;
        else{
            pos = n-sum+1;
        }
        for(int j=pos; j<=pos+step[i]-1; j++)
            ans[j]=i+1;
        sum -= step[i];
        pos += step[i]-1;
    }
    for(int i=1; i<=n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}