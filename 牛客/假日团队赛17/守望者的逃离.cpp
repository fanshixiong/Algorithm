#include<bits/stdc++.h>
using namespace std;

int M, S, T;
int main(){
	cin >> M  >> S >> T ;
	int sect[10] = {7, 7, 3, 3, 3, 3, 2, 2, 2, 2};
	int dist[10] = {102, 102, 34, 34, 34, 34, 17, 102, 102, 17};
	int tp = S, t=T;
	while(M >= 10 && S>0 && T > 0){
		if(S>17){
			S -= 60;
			M -= 10;
			T--;
		}
		else{
			cout << "Yes" << endl << t-T+1 << endl;
		}
	}
	//cout << M << " " << S << " " <<T << endl;
	while(T>0 && S>0){
		if((M == 0 || M == 1) && S > 102 && T >= 7){
			T -= 7;
			S -= 120;
		}
		else if(M>=2 && M <=5 && T >= 3 && S > 34){
			M-=2; T-=3; S-=60;
		}
		else if(M >= 6 && T >= 2 && S > 17){
			M -= 6; T -= 2; S -= 60;
		}
		else {
			S -= 17; T--;
		}
	}
	if(S<=0){
		cout <<"Yes" << endl;
		cout << t-T << endl;
		return 0;
	}
	else{
		cout << "No" << endl << tp - S << endl;
	}
	return 0;
} 
