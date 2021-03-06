

### 分数



#### 题目

1/1 + 1/2 + 1/4 + 1/8 + 1/16 + .... 
每项是前一项的一半，如果一共有20项, 求这个和是多少，结果用分数表示出来。
类似：3 / 2     当然，这只是加了前2项而已。分子分母要求互质。

`注意`：需要提交的是已经约分过的分数，中间任何位置不能含有空格。请不要填写任何多余的文字或符号。



#### 思路

通分，暴力求和，找满足最大公约数为一即为答案。



#### 代码

```cpp
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main(){
	int i, j, b=1, c=0, a=1;
	for(i=1; i<20; i++){
		a = a*2;
		b += a;
	}
	int t = gcd(b, a);
	while(t != 1){
		b /= t;
		a /= t;
		t = gcd(b, a);
	}
	printf("%d/%d\n",b,a);
	return 0;
} 
```



>   答案：1048575/524288



### 星期一



#### 题目

整个20世纪（1901年1月1日至2000年12月31日之间），一共有多少个星期一？(不要告诉我你不知道今天是星期几)

`注意`：需要提交的只是一个整数，不要填写任何多余的内容或说明文字。



#### 思路

利用excel，找到$\ 天 \ 数 / \  7 $即为答案。



![img](F:\c++\Game\LanQiao\历届试题\第九届蓝桥杯大赛个人赛省赛（软件类）真题\A.assets\`OW_{T53$LI1XYE4R@55X0.png)

>   答案：**5217**





### 乘积尾零



#### 题目

如下的10行数据，每行有10个整数，请你求出它们的乘积的末尾有多少个零？

`5650 4542 3554 473 946 4114 3871 9073 90 4329 
2758 7949 6113 5659 5245 7432 3051 4434 6704 3594 
9937 1173 6866 3397 4759 7557 3070 2287 1453 9899 
1486 5722 3135 1170 4014 5510 5120 729 2880 9019 
2049 698 4582 4346 4427 646 9742 7340 1230 7683 
5693 7015 6887 7381 4172 4341 2909 2027 7355 5649 
6701 6645 1671 5978 2704 9926 295 3125 3878 6785 
2066 4247 4800 1578 6652 4616 1113 6205 3264 2915 
3966 5291 2904 1285 2193 1428 2265 8730 9436 7074 
689 5510 8243 6114 337 4096 8199 7313 3685 211 `



#### 思路

找到5和2的个数中的最小值。



#### 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
int nums[10][10] = { 
5650,4542,3554,473,946,4114,3871,9073,90,4329,
2758,7949,6113,5659,5245,7432,3051,4434,6704,3594,
9937,1173,6866,3397,4759,7557,3070,2287,1453,9899,
1486,5722,3135,1170,4014,5510,5120,729,2880,9019,
2049,698,4582,4346,4427,646,9742,7340,1230,7683,
5693,7015,6887,7381,4172,4341,2909,2027,7355,5649,
6701,6645,1671,5978,2704,9926,295,3125,3878,6785,
2066,4247,4800,1578,6652,4616,1113,6205,3264,2915,
3966,5291,2904,1285,2193,1428,2265,8730,9436,7074,
689,5510,8243,6114,337,4096,8199,7313,3685,211,
};
int main(){
	int cnt2 = 0, cnt5=0, ans = 0;
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			int x = nums[i][j];
			while(x % 2 == 0){
				cnt2++;
				x /= 2;
			}
			while(x % 5 == 0){
				cnt5++;
				x /= 5;
			}
		}
	}
	cout << cnt2 << " " << cnt5 << endl;
	cout << min(cnt2, cnt5) << endl;
	return 0;
} 
```



>   答案：31



### 第几个幸运数



#### 题目

小明到x星球旅行的游客都被发给一个整数，作为游客编号。 x星的国王有个怪癖，他只喜欢数字3,5和7。国王规定，游客的编号如果只含有因子：3,5,7,就可以获得一份奖品。

我们来看前10个幸运数字是： 3 5 7 9 15 21 25 27 35 45     因而第11个幸运数字是：49

小明领到了一个幸运数字 59084709587505，他去领奖的时候，人家要求他准确地说出这是第几个幸运数字，否则领不到奖品。 请你帮小明计算一下，59084709587505是第几个幸运数字



#### 思路

动态规划，$dp[i] = min(dp[p_3]*3,dp[p_5]*5,dp[p_7]*7)$,  初始时$p_3 = 0, p_5 = 0, p_7 = 0$,  $dp[0] = 1$

#### 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+10;
ll f3 = 0, f5 = 0, f7 = 0;
ll f[maxn];
ll n = 59084709587505;
int main(){
	f[0] = 1;
	ll i;
	for(i = 1; f[i-1] < n; i++){
		f[i] = min(min(f[f3]*3, f[f5]*5), f[f7]*7);
		if(f[i] / f[f3] == 3) f3++;
		if(f[i] / f[f5] == 5) f5++;
		if(f[i] / f[f7] == 7) f7++;
	}
	cout << i-1 << endl;
	return 0;
} 
```

>   答案：1905



### 打印图形



#### 题目

如下的程序会在控制台绘制分形图（就是整体与局部自相似的图形）。

当n = 1, 2, 3的时候，输出如下：
请仔细分析程序，并填写划线部分缺少的代码。

```cpp
n=1时：
 o 
ooo
 o 

n=2时：
    o    
   ooo   
    o    
 o  o  o 
ooooooooo
 o  o  o 
    o    
   ooo   
    o    

n=3时
             o             
            ooo            
             o             
          o  o  o          
         ooooooooo         
          o  o  o          
             o             
            ooo            
             o             
    o        o        o    
   ooo      ooo      ooo   
    o        o        o    
 o  o  o  o  o  o  o  o  o 
ooooooooooooooooooooooooooo
 o  o  o  o  o  o  o  o  o 
    o        o        o    
   ooo      ooo      ooo   
    o        o        o    
             o             
            ooo            
             o             
          o  o  o          
         ooooooooo         
          o  o  o          
             o             
            ooo            
             o      
```





#### 思路       

搞清各个变量的含义，t 代表的是几行



#### 代码

```cpp
#include <stdio.h>
#include <stdlib.h>

void show(char* buf, int w){
	int i,j;
	for(i=0; i<w; i++){
		for(j=0; j<w; j++){
			printf("%c", buf[i*w+j]==0? ' ' : 'o');
		}
		printf("\n");
	}
}

void draw(char* buf, int w, int x, int y, int size){
	if(size==1){
		buf[y*w+x] = 1;
		return;
	}
	
	int n = size/3; //填空
	draw(buf, w, x, y, n);
	draw(buf, w, x-n, y ,n);
	draw(buf, w, x+n, y ,n);
	draw(buf, w, x, y-n ,n);
	draw(buf, w, x, y+n ,n);
}

int main()
{
	int N = 2;
	int t = 1;
	int i;
	for(i=0; i<N; i++) t *= 3;
	
	char* buf = (char*)malloc(t*t);
	for(i=0; i<t*t; i++) buf[i] = 0;
	
	draw(buf, t, t/2, t/2, t);
	show(buf, t);
	free(buf);
	
	return 0;
}
```



### 航班时间



#### 题目

【问题背景】
小h前往美国参加了蓝桥杯国际赛。小h的女朋友发现小h上午十点出发，上午十二点到达美国，于是感叹到“现在飞机飞得真快，两小时就能到美国了”。小h对超音速飞行感到十分恐惧。仔细观察后发现飞机的起降时间都是当地时间。由于北京和美国东部有12小时时差，故飞机总共需要14小时的飞行时间。不久后小h的女朋友去中东交换。小h并不知道中东与北京的时差。但是小h得到了女朋友来回航班的起降时间。小h想知道女朋友的航班飞行时间是多少。

【问题描述】
对于一个可能跨时区的航班，给定来回程的起降时间。假设飞机来回飞行时间相同，求飞机的飞行时间。

【输入格式】
从标准输入读入数据。 一个输入包含多组数据。输入第一行为一个正整数T，表示输入数据组数。每组数据包含两行，第一行为去程的 起降 时间，第二行为回程的 起降 时间。
起降时间的格式如下

$h1:m1:s1 \ \ h2:m2:s2 $或
$h1:m1:s1 \ \ h3:m3:s3 (+1) $或
$h1:m1:s1 \ \ h4:m4:s4 (+2)$
表示该航班在当地时间$h1$时$m1$分$s1$秒起飞，

第一种格式表示在当地时间 当日 $h2$时$m2$分$s2$秒降落
第二种格式表示在当地时间 次日 $h3$时$m3$分$s3$秒降落。
第三种格式表示在当地时间 第三天 $h4$时$m4$分$s4$秒降落。

对于此题目中的所有以$ h : m : s $形式给出的时间, 保证 $( 0<=h<=23, 0<=m,s<=59 )$.

【输出格式】
输出到标准输出。 对于每一组数据输出一行一个时间$hh:mm:ss$，表示飞行时间为$hh$小时$mm$分$ss$秒。注意，当时间为一位数时，要补齐前导零。如三小时四分五秒应写为$03:04:05$。

【样例输入】
$3$
$17:48:19 \ \  21:57:24$
$11:05:18 \ \ 15:14:23$
$17:21:07 \ \  00:31:46 (+1)$
$23:02:41 \ \  16:13:20 (+1)$
$10:19:19 \ \  20:41:24$
$22:19:04 \ \ 16:41:09 (+1)$

【样例输出】
$04:09:05$
$12:10:39$
$14:22:05$

【限制与约定】
保证输入时间合法，飞行时间不超过24小时。



#### 思路

字符串处理



#### 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
char str[50];
//初始化字符串数组
void init(){
    for(int i=0;i<35;i++){
        str[i]='0';
    }
}
//string to int
int str2int(char h1,char h2,char m1,char m2,char s1,char s2){
    cout<<h1<<h2<<" "<<s1<<s2<<endl;
    int hts=((h1-'0')*10+(h2-'0'))*3600;
    int mts=((m1-'0')*10+(m2-'0'))*60;
    int sec=hts+mts+((s1-'0')*10+(s2-'0'));
    cout<<hts<<" "<<mts<<" "<<sec<<endl;
    return sec;
}
//int to string  &  display
int int2str(int t){
    int h=t/3600;
    int m=(t-h*3600)/60;
    int s=t-h*3600-m*60;
    switch(((h>=10)?1:0)){
        case 0:cout<<"0"<<h<<":";
                break;
        default: cout<<h<<":";
                break;
    }
    switch(((m>=10)?1:0)){
        case 0:cout<<"0"<<m<<":";
                break;
        default: cout<<m<<":";
                break;
    }
    switch(((s>=10)?1:0)){
        case 0:cout<<"0"<<s<<endl;
                break;
        default: cout<<s<<endl;
                break;
    }
}
int main(){
    int t;
    cin>>t;
    getchar();//读取一个字符串，消除"\n"的影响
    int t1s,t1e,t1,t2s,t2e,t2,final;
    while(t--){
        init();
        gets(str);//获取一行字符串
        t1s=str2int(str[0],str[1],str[3],str[4],str[6],str[7]);
        t1e=str2int(str[9],str[10],str[12],str[13],str[15],str[16]);
        if(str[19]=='+'){
            t1e+=(str[20]-'0')*(3600*24);
        }
        t1=t1e-t1s;
        cout<<t1<<endl;
        init();
        gets(str);
        t2s=str2int(str[0],str[1],str[3],str[4],str[6],str[7]);
        t2e=str2int(str[9],str[10],str[12],str[13],str[15],str[16]);
        if(str[19]=='+'){
            t2e+=(str[20]-'0')*(3600*24);
        }
        t2=t2e-t2s;
        cout<<t2<<endl;
        final=(t2+t1)/2;
        cout<<final<<endl;
        int2str(final);
    }
}
```



### 三体攻击



#### 题目

【题目描述】
     三体人将对地球发起攻击。为了抵御攻击，地球人派出了 $A × B × C$ 艘战舰，在太空中排成一个$ A$ 层 $B$ 行$ C$ 列的立方体。其中，第 $i$ 层第 $j$ 行第 $k $列的战舰（记为战舰 $(i, j, k)$）的生命值为 $d(i, j, k)$。

​      三体人将会对地球发起 $m $轮“立方体攻击”，每次攻击会对一个小立方体中的所有战舰都造成相同的伤害。具体地，第 t 轮攻击用 7 个参数 $lat, rat, lbt, rbt, lct, rct, ht $描述；

      * 所有满足$ i ∈ [lat, rat],j ∈ [lbt, rbt],k ∈ [lct, rct]$ 的战舰 $(i, j, k) $会受到$ h_t $的伤害。如果一个战舰累计受到的总伤害超过其防御力，那么这个战舰会爆炸。

地球指挥官希望你能告诉他，第一艘爆炸的战舰是在哪一轮攻击后爆炸的。

【输入格式】
从标准输入读入数据。 第一行包括 4 个正整数$ A, B, C, m$； 第二行包含$ A × B × C $个整数，其中第 $((i − 1)×B + (j − 1)) × C + (k − 1)+1 $个数为$ d(i, j, k)$； 第 3 到第 $m + 2 $行中，第$ (t − 2)$ 行包含 7 个正整数$ lat, rat, lbt, rbt, lct, rct, ht$。

【输出格式】
输出到标准输出。 输出第一个爆炸的战舰是在哪一轮攻击后爆炸的。保证一定存在这样的战舰。

【样例输入】
$2 \  2 \  2 \  3 $
$1 \ 1 \ 1 \ 1 \ 1 \ 1 \ 1 \ 1$
$1 \ 2 \ 1 \ 2 \ 1 \ 1 \ 1$
$1 \ 1 \ 1 \ 2 \ 1 \ 2 \ 1$
$1 \ 1 \ 1 \ 1 \ 1 \ 1 \ 2$

【样例输出】
$2$

【样例解释】
在第 2 轮攻击后，战舰$ (1,1,1) $总共受到了 2 点伤害，超出其防御力导致爆炸。

【数据约定】
对于 10% 的数据，$B = C = 1$；
对于 20% 的数据，$C = 1$；
对于 40% 的数据，$A × B × C, m ≤ 10, 000$；
对于 70% 的数据，$A, B, C ≤ 200$；
对于所有数据，$A × B × C ≤ 10^6, m ≤ 10^6, 0 ≤ d(i, j, k), ht ≤ 10^9。$



#### 思路

满分题解：三维差分。

考试中：暴力。



#### 代码

```cpp
#include<bits/stdc++.h>

using namespace std;
 
int a[200][200][200];
 
int main() {
	freopen("7.txt", "r", stdin);
	
	int A, B, C, m;
	scanf("%d%d%d%d", &A, &B, &C, &m);
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			for (int k = 0; k < C; k++)
				scanf("%d", &a[i][j][k]);
		}
	}
	int lat, rat, lbt, rbt, lct, rct, ht;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d%d%d%d", &lat, &rat, &lbt, &rbt, &lct, &rct, &ht);
		for (int j = lat - 1; j <= rat - 1; j++) {
			for (int k = lbt - 1; k <= rbt - 1; k++) {
				for (int p = lct - 1; p <= rct - 1; p++) {
					a[j][k][p] -= ht;
					if (a[j][k][p] < 0) {
						printf("%d\n", i);
						exit(0);
					}
				}
			}
		}
	}
	return 0;
}
```



### 全球变暖

#### 题目

标题：全球变暖

【题目描述】
你有一张某海域$NxN$像素的照片，"."表示海洋、"#"表示陆地，如下所示：

```cpp
.......
.##....
.##....
....##.
..####.
...###.
.......
```



其中"上下左右"四个方向上连在一起的一片陆地组成一座岛屿。例如上图就有2座岛屿。  

由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。  

例如上图中的海域未来会变成如下样子：

```cpp
.......
.......
.......
.......
....#..
.......
.......
```



请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。  

【输入格式】
第一行包含一个整数N。  (1 <= N <= 1000)  
以下N行N列代表一张海域照片。  

照片保证第1行、第1列、第N行、第N列的像素都是海洋。  

【输出格式】
一个整数表示答案。

【样例输入】

```cpp
7 
.......
.##....
.##....
....##.
..####.
...###.
.......  
```



【样例输出】
1  



#### 思路

连通块中'#'的个数等于相邻的'.'的个数时，这个联通块会被淹没。



#### 代码

```cpp
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;


int dist[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int vis[maxn][maxn];
string maps[maxn];
int n, ans = 0;

void bfs(int x, int y){
	queue<pair<int, int> > q;
	q.push({x, y});
	vis[x][y] = 1;
	
	int cnt_l = 1, cnt_s = 0;
	if((x>0 && maps[x-1][y]=='.') || (y>0 && maps[x][y-1]=='.') || (x<n-1 && maps[x+1][y]=='.') || (y<n-1 && maps[x][y+1]=='.')) { 
		cnt_s++;
		maps[x][y] = '*';
	}
	while(!q.empty()){
		pair<int, int> u = q.front(); q.pop();
		
		int x1 = u.first, y1 = u.second;
		
		for(int i = 0; i < 4; i++){
			int _x = x1 + dist[i][0];
			int _y = y1 + dist[i][1];
			
			if(_x < 0 || _y < 0 || _x >= n || _y >= n) continue;
			
			if(vis[_x][_y] || maps[_x][_y] == '.') continue;
			
			cnt_l ++;
			vis[_x][_y] = 1;
			q.push({_x, _y});
			
			if((_x>0 && maps[_x-1][_y]=='.') || (_y>0 && maps[_x][_y-1]=='.') || (_x<n-1 && maps[_x+1][_y]=='.') || (_y<n-1 && maps[_x][_y+1]=='.')) { 
				cnt_s++;
				maps[_x][_y] = '*';
			}
		}
	}
	if(cnt_l == cnt_s) ans++;
}

int main(){
	memset(vis, 0, sizeof vis);
	freopen("7.txt", "r", stdin);
	cin >> n; 
	// string s;
	// int c = 0;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		maps[i] = s;
	}
	// while(cin >> s) maps[c++] = s;
	
	for(int i = 0; i < n; i++) cout << maps[i] << endl;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!vis[i][j] && maps[i][j] == '#') bfs(i, j);
		}
	}
	
	cout << endl;
	for(int i = 0; i < n; i++) cout << maps[i] << endl;
	
	cout << ans << endl;
	return 0;
}
```



### 倍数问题



#### 题目

【题目描述】
众所周知，小葱同学擅长计算，尤其擅长计算一个数是否是另外一个数的倍数。但小葱只擅长两个数的情况，当有很多个数之后就会比较苦恼。现在小葱给了你 n 个数，希望你从这 n 个数中找到三个数，使得这三个数的和是 K 的倍数，且这个和最大。数据保证一定有解。

【输入格式】
从标准输入读入数据。

第一行包括 2 个正整数 n, K。
第二行 n 个正整数，代表给定的 n 个数。

【输出格式】
输出到标准输出。
输出一行一个整数代表所求的和。



【样例入】
4 3
1 2 3 4

【样例输出】
9

【样例解释】
选择2、3、4。



#### 思路

正解：三维背包？

暴力完事。



#### 代码

```cpp
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
int a[maxn];
int main(){
	
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a+n);
	for(int i = n-1; i>=0; i--){
		for(int j = i-1; j>=0; j--){
			for(int p = j-1; p>=0; p--){
				int sum = a[i] + a[j] + a[p];
				if(sum % k == 0){
					cout << a[i] << " " << a[j] << " " << a[p] << endl;
 					cout << sum << endl;
					return 0;
				}
			}
		}
	}
	
	return 0;
} 
```







### 付账问题



#### 题目

【题目描述】
几个人一起出去吃饭是常有的事。但在结帐的时候，常常会出现一些争执。

现在有 $n$ 个人出去吃饭，他们总共消费了$ S $元。其中第$ i $个人带了$a_i$ 元。幸运的是，所有人带的钱的总数是足够付账的，但现在问题来了：每个人分别要出多少钱呢？

为了公平起见，我们希望在总付钱量恰好为 $S $的前提下，最后每个人付的钱的标准差最小。这里我们约定，每个人支付的钱数可以是任意非负实数，即可以不是$1$分钱的整数倍。你需要输出最小的标准差是多少。

标准差的介绍：标准差是多个数与它们平均数差值的平方平均数，一般用于刻画这些数之间的“偏差有多大”。形式化地说，设第$ i $个人付的钱为$ b_i $元，那么标准差为 : $s=\sqrt{\frac{1}{n} \sum_{i=1}^{n}\left(b_{i}-\frac{1}{n} \sum_{i=1}^{n} b_{i}\right)^{2}}$



【输入格式】
从标准输入读入数据。

第一行包含两个整数 $n、S$；
第二行包含 n 个非负整数 $a_1, ..., a_n。$

【输出格式】
输出到标准输出。

输出最小的标准差，四舍五入保留 4 位小数。
保证正确答案在加上或减去 10^−9 后不会导致四舍五入的结果发生变化。

【样例1输入】
$5 \ 2333$
$666 \  666 \  666  \ 666  \ 666$

【样例输出】
$0.0000$

【样例解释】
每个人都出 $2333/5$ 元，标准差为 $0$。

再比如：
【样例输入】
$10 \ 30$
$2 \  1 \  4 \ 7 \  4 \  8 \  3 \  6 \  4 \  7  $

【样例输出】
$0.7928$

【数据说明】
对于 10% 的数据，所有 $a_i$ 相等；
对于 30% 的数据，所有非 0 的 $a_i$ 相等；
对于 60% 的数据，$n ≤ 1000；$
对于 80% 的数据，$n ≤ 10^5$；
对于所有数据，$n ≤ 5 × 10^5, 0 ≤ a_i ≤ 10^9$。



#### 思路

贪心，将不能够付起平均值的钱平均分给可以付起的人。



#### 代码

```cpp
#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e5+10;

double a[maxn];


int main(){
	int n, S;
	cin >> n >> S;
	
	double avg = 1.0 * S / n;
	
	for(int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a + n);
	
	double ans = 0.0, navg = avg;
	for(int p = 0; p < n; p++){
		if(a[p] < navg){
			ans += (double)pow(avg-a[p], 2);
			S -= a[p];
			navg = 1.0 * S / (n-p-1);
		}
		else{
			ans += (double)pow(navg-avg, 2);
		}
	}
	
	printf("%.4lf", sqrt(ans/n));
	return 0;
}
```

