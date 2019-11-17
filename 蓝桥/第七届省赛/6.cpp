#include<iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> num(14, 0);
	int res = 5;
	for (int i = 1; i < 14; i++){
		
		for (int j = 1; j < 14; j++){
			for (int k = 1;  k < 14; k++){
				if (j !=i && k !=i && k != j && i + j == k){
					for (int x = 1; x < 14; x++){
						for (int y = 1; y < 14; y++){
							for (int z = 1; z < 14; z++){
								if ((z != y && z != x && z != i && z != j && z != k) &&  (y != x && y != i && y != j && y != k) && (x != i && x != j && x != k) && x-y == z){
									for(int q = 1; q < 14; q++){
										if(q!=i&&q!=j&&q!=k&&q!=x&&q!=y&&q!=z){
											for(int w = 1; w < 14; w++){
												if (w!=q&&w!=i&&w!=j&&w!=k&&w!=x&&w!=y&&w!=z){
													for (int e = 1; e < 14; e++){
														if (e!=w&&e!=q&&e!=i&&e!=j&&e!=k&&e!=x&&e!=y&&e!=z){
															if(q*w==e){
																for (int a = 1; a < 14; a++){
																	if (a!=e&&a!=w&&a!=q&&a!=i&&a!=j&&a!=k&&a!=x&&a!=y&&a!=z){
																		for (int b = 1; b < 14; b++){
																			if(b!=a&&b!=e&&b!=w&&b!=q&&b!=i&&b!=j&&b!=k&&b!=x&&b!=y&&b!=z){
																				for (int c = 1; c < 14; c++){
																					if (c!=b&&c!=a&&c!=e&&c!=w&&c!=q&&c!=i&&c!=j&&c!=k&&c!=x&&c!=y&&c!=z){
																						if (a/b==c){
																							res++;
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << res << endl;
	return 0;
} 
