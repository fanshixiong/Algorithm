#include <iostream>
#include <cmath>
#include <vector> 
#include <cstring>
using namespace std;
int main(){
	char c;
	vector<vector<int> > race_21(100000, vector<int> (2));
	int k = 0;
	int hua_11 = 0, tra_11 = 0, hua_21 = 0, tra_21 = 0;
	while(cin >> c && c != 'E'){
		if(c == 'W'){
			hua_11++; hua_21++;
		}
		else{
			tra_11++; tra_21++;
		}
		if((hua_11 >= 11 || tra_11 >= 11) && (abs(hua_11-tra_11) >= 2)){
			cout << hua_11 << ":" << tra_11 << endl;
			hua_11=tra_11=0;
		}
		if((hua_21 >= 21 || tra_21 >= 21) && (abs(hua_21-tra_21) >= 2)){
			race_21[k][0] = hua_21; race_21[k++][1] = tra_21;
			hua_21 = tra_21 = 0;
		}
	}
	cout << hua_11 << ":" << tra_11 << endl << endl;
	for(int i = 0; i < k; i++){
		cout << race_21[i][0] << ":" << race_21[i][1] << endl;
	} 
	cout << hua_21 << ":" << tra_21 << endl;
	return 0;
} 
