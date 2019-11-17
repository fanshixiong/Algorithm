/*#include<iostream>
#include<algorithm>
using namespace std;
struct f
{
    int rank,sum;//定义结构体，将行号与0的个数对应 
}cou[10];
int a[10][10],hang[10][10],lie[10][10],gong[10][10],s[100][4],u,ok,most=-1,have;
int which(int,int);//给出两个整型变量代表坐标，返回此坐标的所在宫                                     
int point(int,int);//给出两个整型变量代表坐标，返回此坐标的分值                                                                  
void dfs(int,int); 
void print(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cout << s[i][j]<< " ";
		}
		cout << endl;
	}
}
bool cmp(f a,f b)
{
    return a.sum<b.sum; 
}
int main()
{
    for(int i=1;i<=9;i++)  cou[i].rank=i;//rank存其初始行号，排序后就不会丢失 
    for(int i=1;i<=9;i++)
    for(int j=1;j<=9;j++)
    {
        cin>>a[i][j];
        if(a[i][j]>0)
        hang[i][a[i][j]]=lie[j][a[i][j]]=gong[which(i,j)][a[i][j]]=1,have+=a[i][j]*point(i,j);//非零就不存储到搜索数组s中，但将这个点的值在其所在行、列、宫中标记 ，计算加分 
        else  cou[i].sum++;//是0就计数 
    }
    sort(cou+1,cou+10,cmp);//排序，0少的在前 
    for(int i=1;i<=9;i++)//整理s数组，准备搜索 
    {
        for(int j=1;j<=9;j++)//先搜0少的行 
        if(a[cou[i].rank][j]==0)
        s[u][0]=cou[i].rank,s[u][1]=j,s[u][2]=point(cou[i].rank,j),s[u++][3]=which(cou[i].rank,j);//保存不解释 
    }
    dfs(0,have);//搜索 
    cout<<most<<endl;//most保存答案，初始值为-1 
    return 0;
} 

void dfs(int p,int score)// 表示正在搜s[p],score为目前分数 
{
    if(p==u)//合法填完了所有的数 
    {
        if(score>most)  most=score;//更大就更新 
       // print();
       // cout << score << endl;
		//cout << endl; 
        return;
    }
    for(int i=1;i<=9;i++) 
    {
        if(!hang[s[p][0]][i]&&!lie[s[p][1]][i]&&!gong[s[p][3]][i])//判断可不可以将i填入 
        {
            hang[s[p][0]][i]=lie[s[p][1]][i]=gong[s[p][3]][i]=1;//填了后就将这个点的值在其所在行、列、宫中标记
            dfs(p+1,score+(s[p][2]*i));//下一层递归 
            hang[s[p][0]][i]=lie[s[p][1]][i]=gong[s[p][3]][i]=0;//回溯 
        }
    }
    return;
}

int which(int i,int j)
{
    if(i<=3)
    {
        if(j<=3)        return 1;
        else if(j<=6)   return 2;
        else            return 3;
    }
    else if(i<=6)
    {
        if(j<=3)        return 4;
        else if(j<=6)    return 5;
        else            return 6;
    }
    else
    {
        if(j<=3)        return 7;
        else if(j<=6)   return 8;
        else            return 9;
    }
}

int point(int i,int j)
{
    if(i==1||j==1||i==9||j==9)   return 6;
    if(i==2||j==2||i==8||j==8)     return 7;
    if(i==3||j==3||i==7||j==7)   return 8;
    if(i==4||j==4||i==6||j==6)   return 9;
    return 10;
}*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std ;


int ninth( int i , int j ) {
    if( i <= 3 && j <= 3 ) return 1 ;
    if( i <= 3 && j <= 6 ) return 2 ;
    if( i <= 3  ) return 3 ;
    if( i <= 6 && j <= 3 ) return 4 ;
    if( i <= 6 && j <= 6 ) return 5 ;
    if( i <= 6 ) return 6 ;
    if( j <= 3 ) return 7 ;
    if( j <= 6 ) return 8 ;
    return 9 ;
}

int point[ 6 ] = { 0 , 6 , 7 , 8 , 9 , 10} ;
int map[ 10 ][ 10 ] ;
long long ans = -1 ;
struct node {
    int line , sum ;
}sss[ 11 ] ;
bool cmp( node i , node j ) {
    return i.sum < j.sum ;
}
bool line[ 10 ][ 10 ] , nine[ 10 ][ 10 ] , list[ 10 ][ 10 ] ;
int dfs( int , int , int );
int print( );

int main( )
{
    for( int i = 1 ; i <= 9 ; ++i ) {
        int k = 0 ;
        for( int j = 1 ; j <= 9 ; ++j ) {
            cin >> map[ i ][ j ];
            if( !map[ i ][ j ] ) ++k;
            line[ i ][ map[ i ][ j ] ] = 1 ;
            nine[ ninth( i , j ) ][ map[ i ][ j ] ] = 1 ;
            list[ j ][ map[ i ][ j ] ] = 1 ; 
        }
        sss[ i ].sum = k , sss[ i ].line = i ;
    }
    sort( sss + 1 , sss + 10 , cmp );
    dfs( 1 , sss[ 1 ].line , 1 ) ;
    printf( "%lld" , ans );
    return 0 ;
}
int dfs( int h , int x , int y ) {
    if( h == 10 ) {
        print( );
        return 0 ;
    }
    if( y == 10 ) {
        dfs( h + 1 , sss[ h + 1 ].line , 1 );
        return 0 ;
    }
    if( !map[ x ][ y ] ) {
        for( int i = 1 ; i <= 9 ; ++i ) {
            if( line[ x ][ i ] == 0 && list[ y ][ i ] == 0 && nine[ ninth( x , y ) ][ i ] == 0 ){
                line[ x ][ i ] = 1 , list[ y ][ i ] = 1 , nine[ ninth( x , y ) ][ i ] = 1 ;
                map[ x ][ y ] = i ;
                dfs( h , x , y + 1 );
                map[ x ][ y ] = 0 ;
                line[ x ][ i ] = 0 , list[ y ][ i ] = 0 , nine[ ninth( x , y ) ][ i ] = 0 ;
            }
        }
    }
    else dfs( h , x , y + 1 );
}
int print( ) {
    long long sum = 0 ;
    for( int i = 1 ; i <= 9 ; ++i ) {
        for( int j = 1 ; j <= 9 ; ++j ) {
            sum += ( map[ i ][ j ] * point[ min( min( i , 10 - i ) , min ( j , 10 - j ) ) ] );
        }
    }
    ans = max( ans , sum );
}
