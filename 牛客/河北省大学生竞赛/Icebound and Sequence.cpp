#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
long long qsm(long long a, long long b, long long c){
    long long ans=1;
    while(b){
        if(b&1)
            ans=(ans*a)%c;
        b>>=1;
        a=(a*a)%c;
    }
    //cout << a << " " << b << " " << ans << endl;
    return ans%c;
}
//¶þ·ÖÈ¡ÃÝ 
long long solve(long long q, long long n, long long p){
    if(n==1)
        return q%p;
    if(n==0)
        return 1;
    if(n%2==0){
        return ((qsm(q, n/2, p)+1)%p * solve(q, n/2, p)%p)%p;
    }
    else{
        return (qsm(q, n, p)%p + solve(q, n-1, p)%p)%p;
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        long long n, p, q;
        scanf("%lld%lld%lld", &q, &n, &p);
        if(q==1){
            printf("%lld", n%p);
            continue;
        }
        long long ans=solve(q, n, p);
        printf("%lld\n", ans);
    }
    return 0;
}
