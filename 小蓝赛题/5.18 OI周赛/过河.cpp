#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
const int maxl = 300 * 105;

int L,s,t,m,stone[maxn],a[maxn],dp[maxl],base;
//stone����ʯͷ�ĳ�ʼλ�ã�aΪ���ǽ�ʯͷ��ʼ�����ʯͷλ�ã�
bool vis[maxl];
//���һ�������ϵĸõ��Ƿ�Ϊʯͷ��
int main()
{
    ios::sync_with_stdio(0);// �ӿ�cin���ٶ�
    cin >> L;
    cin >> s >> t >> m;
    base = s * t;
    for(int i = 1 ; i <= m ; ++ i)
        cin >> stone[i];
    sort(stone + 1,stone + 1 + m);
//  �ж�s == t�����
    if(s == t){
        int cnt =0;
        for(int i = 1 ; i <= m ; ++ i)
            if(stone[i] % s == 0)cnt++;
        cout << cnt << endl;
        return 0;
    }
    for(int i = 1 ; i <= m ; ++ i){//    ��ɢ������
        int d = stone[i] - stone[i - 1];
        if(d >= base)d = base;
        a[i] = a[i - 1] + d;
        vis[a[i]] = 1;
    }
    L = a[m] + base;
//  ��L������һ��ʯͷ��λ��+s*t
//  ���L - a[m] >= s * t������s * t
//  ���L - a[m] <= s * t�ͼ���һ����ʹ�����������������Ϊ���ܿ���������ľ��
    memset(dp,0x7f,sizeof(dp));
    dp[0] = 0;
    for(int i = 1 ; i <= L ; ++ i)
        for(int j = s ; j <= t ; ++ j){
            if(i - j >= 0){
                if(vis[i])dp[i] = min(dp[i - j] + 1,dp[i]);
                else dp[i] = min(dp[i - j],dp[i]);
            }
        }
    int ans = maxn;
    for(int i = a[m] ; i <= L ; ++ i)
        ans = min(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
