 #include <iostream>
 #include <cmath>
 #include <vector>
 #include <algorithm>
 #include <queue>
 using namespace std;
 int dist[4][2]={0, 1, 0, -1, 1, 0, -1, 0};
 struct node{
 	int x0, y0, step;
 };
 class Scort{
 	int m, n;
 	vector<int> beg;
 	vector<int> end;
 	vector<vector<int> > D;
 	vector<vector<int> > G;
 	vector<vector<bool> > vis;
 	vector<int> best;
 	vector<int> way;
 public:
	Scort(){
		int x;
		cin >> x >> m >> n;
		G.resize(m);
		vis.resize(m); D.resize(m);
		beg.resize(2); end.resize(2); best.resize(2);
		best[0]=0; best[1]=0x3f3f3f3f;
		way.resize(2); 
		cin >> beg[0] >> beg[1] >> end[0] >> end[1];
		for(int i=0; i<m; i++){
			G[i].resize(n); 
			vis[i].resize(n); 
			D[i].resize(n);
		}
		vector<vector<int> > scout(x, vector<int> (2));
		for(int i=0; i<x; i++){
			int a, b;
			cin >> a >> b;
			G[a][b]=1;
			D[a][b]=1;
			scout[i][0]=a; scout[i][1]=b;
		}
		queue<node> q;
		for(int i=0; i<x; i++){
			node tp; tp.x0=scout[i][0]; tp.y0=scout[i][1];
			q.push(tp); 
		}
		while(!q.empty()){
			node tp=q.front();
			q.pop();
			for(int i=0; i<4; i++){
				int x1=tp.x0+dist[i][0];
				int y1=tp.y0+dist[i][1];
				if(judge(x1, y1) && (!D[x1][y1] || D[x1][y1]>D[tp.x0][tp.y0]+1)){
					D[x1][y1]=D[tp.x0][tp.y0]+1;
					node g; g.x0=x1; g.y0=y1;
					q.push(g); 
				}
			}
		}
		/*
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cout << D[i][j] << " ";
			}
			cout << endl;
		}*/
	}
	bool judge(int x1, int y1){
		if(x1<0 || x1>=m || y1<0 || y1>=n)
			return false;
		return true;
	}
	int dfs(int x0, int y0, int step, int val){
		//if(beg[0]==end[0] && beg[1]==end[1]) return 0;
		/*if(way[0]<best[0] || way[1]>best[1] || D[x0][y0] < best[0]) return false;
		if(x0==end[0] && y0==end[1]){
			//cout << way[0] << " " << way[1] << endl;
			if(best[0]<=way[0] && best[1]>=way[1]){
				best[0]=way[0];
				best[1]=way[1];
			}
			return true;
		}
		*/
		if(x0==end[0] && y0==end[1]) return step;
		//cout << x0 <<" "<< y0 << " " << val <<" " <<step << endl;
		for(int i=0; i<4; i++){
			int x1=x0+dist[i][0];
			int y1=y0+dist[i][1];
			if(judge(x1, y1) && (!vis[x1][y1]) && !G[x1][y1] && D[x1][y1]-1 >= val){
				vis[x1][y1]=1;
				//int h=way[0];
				//way[0]=min(D[x1][y1], way[0]);
				//way[1]++;
				return dfs(x1, y1,step+1, val);
				//way[0]=h;
				//way[1]--;
				//vis[x1][y1]=0;
			}
		}
		if(!b)	
			return -1;
		return tp;
	}
	void init(){
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				vis[i][j]=0;
			}
		}
	}
	void resolve(){
		way[0]=D[beg[0]][beg[1]];
		way[1]=0;
		int L=0, R=D[beg[0]][beg[1]]-1;
		while(L<=R){
			int M=(L+R)>>1;
			init();
			int tp=dfs(beg[0], beg[1], 0, M);
			
			if(tp==-1)
				R=M-1;
			else
				L=M+1, best[0]=M, best[1]=tp;
		}
		cout << best[0] << " " << best[1] << endl;
	}/*
	int bfs(int val){
		if(beg[0]==end[0]&&beg[1]==end[1]) return 0;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				vis[i][j]=0;
			}
		}
		queue<node> q;
		node tmp; tmp.x0=beg[0]; tmp.y0=beg[1]; tmp.step=0;
		q.push(tmp);
		while(!q.empty()){
			tmp=q.front();
			q.pop();
			for(int i=0; i<4; i++){
				int x1=tmp.x0+dist[i][0];
				int y1=tmp.y0+dist[i][1];
				if(judge(x1, y1) && (!vis[x1][y1]) && !G[x1][y1] && D[x1][y1]-1 >= val){
					vis[x1][y1]=1;
					node to;
					to.x0=x1; to.y0=y1; to.step=tmp.step+1;
					if(x1==end[0] && y1==end[1]) return to.step;
					q.push(to);
				}
			}
		} 
		return -1;
	}
	void resolve(){
		int L=0, R=D[beg[0]][beg[1]]-1;
		while(L<=R){
			int M=(L+R)>>1;
			int tp=bfs(M);
			if(tp==-1)
				R=M-1;
			else
				L=M+1, best[0]=M, best[1]=tp;
		}
		cout << best[0] << " " << best[1] << endl;
	}*/
 };
 int main(){
 	Scort test;
 	test.resolve();
 	return 0;
 } 
