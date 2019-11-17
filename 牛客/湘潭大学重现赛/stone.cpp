#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
using  namespace std;
int n;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        cin >> n;
        long long ans=0, sum=0;
        for(int i=1; i<=n; i++){
            long long x;
            scanf("%lld", &x);
            sum += x;
            ans = max(ans, x);
        }
        printf("%lld\n", sum-ans);
    }
    return 0;
}
