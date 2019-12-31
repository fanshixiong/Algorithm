#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+10;
int pos[maxn], n;
ll sum1[maxn], sum2[maxn];
int lowbit(int x){
    return x&(-x);
}
void add(ll *bit, int pos, int val){
    while(pos < maxn){
        bit[pos] += val;
        pos += lowbit(pos);
    }
}
ll query(ll *bit, int pos){
    ll ans=0;
    while(pos){
        ans += bit[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int Bisection(int i){
    int l=1, r=n+1, mid;
    while(l+1 < r){
        mid = (l+r)/2;
        if(query(sum1, mid) * 2 <= i)
            l=mid;
        else  
            r=mid;
    }
    return l;
}
int bs(ll *bit, int val) {
    int i = 0;
    for(int j = 19; j >= 0; j--) {
        if((i | 1 << j) < maxn) {
            if(bit[i | 1 << j] <= val) {
                val -= bit[i |= 1 << j];
            }
        }
    }
    return i;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    int a;
    for(int i=1; i<=n; i++){
        cin >> a;
        pos[a] = i;
    }
    int mid;
    ll cnt=0;
    for(int i=1; i<=n; i++){
        add(sum1, pos[i], 1);
        cnt += i-query(sum1, pos[i]);
        add(sum2, pos[i], pos[i]);
        //mid = Bisection(i);
        mid = bs(sum1, i/2)+1;
        ll sum = 0;
        ll aa = i/2, bb = i-i/2-1;
        sum += (ll)aa * mid - (ll)aa * (aa+1)/2 - query(sum2, mid-1);
        sum += (query(sum2, maxn) - query(sum2, mid)) - (ll)bb*mid - (ll)bb * (bb+1) / 2;
        cout << sum + cnt << " ";
    }
    cout << endl;
    return 0;
}   