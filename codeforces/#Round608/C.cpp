#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n, sx, sy;
    cin >> n >> sx >> sy;
    int zs=0, ys=0, zx=0, yx=0;
    int s=0, xx=0, z=0, yy=0;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        if(x<sx && y<sy){
            zs++;
        }
        if(x<sx && y>sy){
            ys++;
        }
        if(x>sx && y<sy){
            zx++;
        }
        if(x>sx && y>sy){
            yx++;
        }
        if(x==sx && y<sy){
            z++;
        }
        if(x==sx && y>sy){
            yy++;
        }
        if(y==sy && x<sx){
            s++;
        }
        if(y==sy && x>sx){
            xx++;
        }
    }
    s += (zs+ys);
    xx += (zx+yx);
    yy += (ys+yx);
    z += (zs+zx);
    int maxx = max(s, max(xx, max(yy, z)));
    cout << maxx << endl;
    if(s == maxx){
        cout << sx-1 << " " << sy << endl;
    }
    else if(xx == maxx){
        cout << sx+1 << " " << sy << endl;
    }
    else if(yy == maxx){
        cout << sx << " " << sy+1 << endl;
    }
    else if(z == maxx){
        cout << sx << " " << sy-1 << endl;
    }
    return 0;
}