#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int a, b, c, d , e, f;
    cin >> a >> b >> c >> d >> e >>f ;
    if(e>f){
        if(a >= d){
            cout << d*e << endl;
        }
        else{
            int res = a*e;
            d -= a;
            int minx = min(b, min(c, d));
            cout << res + minx*f << endl;
        }
    }
    else{
        int minx = min(b, c);
        if(minx >= d){
            cout << d*f << endl;
        }
        else{
            int res = minx*f;
            d -= minx;
            int x = min(d, a);
            cout << res + x*e << endl;  
        }
    }
    return 0;
}