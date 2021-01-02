#include<stdio.h>
#define mod 1000000007

long long fastPower(long long n, long long p)
{
    long long ans = 1;
    while (p!=0)
    {
        if (p & 1 == 1)ans = (ans * n) % mod;
        n = (n * n) % mod;
        p >>= 1;
    }
    return ans%mod;
}

int main()
{
    int a,b,m,n;
    scanf("%d %d %d %d",&a,&b,&m,&n);
    long long n1=1;
    long long n2=1;
    long long fn = 0;
    if(n==1||n==2)fn=1;
    for(int i=2;i<n;i++)
    {
        fn = ((a*n2)+(b*n1))%(mod-1);
        n1 = n2;
        n2 = fn;
    }
    printf("%lld\n", fn);
    printf("%lld",fastPower(m,fn));
}