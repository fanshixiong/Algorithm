#include<bits/stdc++.h>
using namespace std;
int n, a[101];
map<int, int> m;
int vis[101];


int main(){
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--){
        memset(vis, 0, sizeof(vis));
        cin >> n;
        vis[0]=1;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            m[a[i]]=i;
        }
        for(int i=1; i<=n; i++){
            if(vis[m[i]])
                continue;
            while(!vis[m[i]-1]){
                swap(a[m[i]], a[m[i]-1]);
                vis[m[i]-1]=1;
                //m[a[j]]=j;
                //m[a[j-1]]=j-1;
                swap(m[i], m[a[m[i]]]);
            }
            vis[m[i]]=1;
            //for(int i=1; i<=n; i++)
            //    cout << m[i] << " ";
            //cout <<endl;
        }
        //cout << endl;
        for(int i=1; i<=n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}