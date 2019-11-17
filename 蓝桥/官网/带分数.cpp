#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> A(10);
bool judge(){
	for (int i = 0; i < 9; i++){
		int a=0;
		for (int j = 0; j <= i; j++){
			a = a*10+A[j];
		}
		if(a<n){
			for (int k = (8-i)/2+1; k <9; k++){
				int b=0, c=0, j=i+1;
				for(; j<k; j++){
					b=b*10+A[j];
				}
				for (;j<9;j++){
					c=c*10+A[j];
				}
				//if(a==3 && c==714)	
				//	cout << a << " " <<b << " " << c << endl;
				if(b%c==0 && a+b/c==n)
					return true;
			}
		}
		else{
			return false;
		}
	}
}
int main(){
	int res = 0;
	cin >> n;
	vector<int> num(11, 0);
	for (int a = 1; a <= 9; a++){
		num[a]++; A[0]=a; 
		for(int b = 1; b <= 9; b++){
			if (!num[b]){
				num[b]++;A[1]=b;
				for (int c = 1; c <= 9; c++){
					if (!num[c]){
						num[c]++;A[2]=c;
						for (int d = 1; d <= 9; d++){
							if(!num[d]){
								num[d]++;A[3]=d;
								for (int e = 1; e <= 9; e++){
									if(!num[e]){
										num[e]++;A[4]=e;
										for (int f=1; f<=9; f++){
											if(!num[f]){
												num[f]++;A[5]=f;
												for(int g=1; g<=9; g++){
													if(!num[g]){
														num[g]++;A[6]=g;
														for(int h=1; h<=9; h++){
															if(!num[h]){
																num[h]++;A[7]=h;
																for(int i=1; i<=9; i++){
																	if(!num[i]){
																		num[i]++;A[8]=i;
																		if(judge())
																			res++;
																		num[i]--;
																	}
																}
																num[h]--;
															}
														}
														num[g]--;
													}
												}
												num[f]--;
											}
										}
										num[e]--;
									}
								}
								num[d]--;
							}
						}
						num[c]--;
					}
				}
				num[b]--;
			}
		}
		num[a]--;
	}
	cout << res << endl;
	return 0;
}
