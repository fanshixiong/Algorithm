#include<iostream>
#include<cstdio>
#define ll long long 
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, K;
        scanf("%d%d", &N, &K);
        ll ans=N;
        if(K==2)
            ans *= N;
        int cnt=0;
		ll X=ans, Y=0;
		while(ans){
			cnt++;
			ans/=10;
		}
        while(cnt!=1){
        	cnt=0;
        	Y=0;
            while(X){
                cnt++;
                Y += X%10;
                X/=10;
            }
            X=Y;
        }
        cout << X << endl;
    }
    return 0;
}
