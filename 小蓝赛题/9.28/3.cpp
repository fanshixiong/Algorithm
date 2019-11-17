#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
bool map[129][129]={1};
int a,b,i,j,n,d,nmax=0,ans=0;
int dx,dy,tempn;
struct DATA{
int x,y,num;
} pub[21];
int dir[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
queue <DATA> que;

bool check(int x,int y){//合法性判定
    if (x < 0 || y < 0 || y > 128 || x >128)
    return false;
    if (map[x][y] == 1)
    return false;
    return true;
    
}



int find(int x,int y){//查找范围内的公共场所
    int anum=0;
    for(i=1;i<=n;i++){
        dx=abs(pub[i].x-x);
        dy=abs(pub[i].y-y);
        if((dx<=d)&&(dy<=d)){
            anum+=pub[i].num;
        }
        
    }
    return anum;
}




int main(){
    cin>>d;
    cin>>n;
    cout << num[3][3] <<endl;
    cout << map[0][1] << endl;
    for(i=1;i<=n;i++){
        scanf("%d%d%d",&pub[i].y,&pub[i].x,&pub[i].num);
    }
        DATA start;
        DATA next,temp;
        start.x=0;
        start.y=0;
        map[0][0]=1;
        que.push(start);
                     // 标准广搜模版
        while(!que.empty()){ 
            temp=que.front();
            tempn=find(temp.x,temp.y);
            if(tempn==nmax)
            ans++;
            if(tempn>nmax){
                nmax=tempn;
                ans=1;
            }
        
            que.pop();
            for(i=0;i<=7;i++){
                next.x=temp.x+dir[i][0];
                next.y=temp.y+dir[i][1];
                if(check(next.x,next.y)==true){
                
                que.push(next);
                map[next.x][next.y]=1;
               
              }
            }
            
        }
    
 cout<<ans<<" "<<nmax;
 return 0;
    
}

