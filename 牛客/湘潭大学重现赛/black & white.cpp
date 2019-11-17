#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T, n, m;
string s;
int Solve(){  //Ë«Ö¸Õë 
    int ans=0;
    int l=0, r=0, cnt=0;
    while(r<n){
        if(s[r]=='0')
            cnt++;
        while(cnt>m){
            if(l<n && s[l]=='0')
                cnt--;
            l++;
        }
        ans = max(ans, r-l+1);
        r++;
    }
    return ans;
}
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        cin >> s;
        int ans = Solve();
        for(int i=0; i<n; i++){
            s[i]=('1'-s[i])+'0';
        }
        printf("%d\n", max(ans, Solve()));
    }
    return 0;
}
