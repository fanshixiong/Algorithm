 /*#include <iostream>
 #include <cstring>
 #include <cstdio> 
 using namespace std;
 int main(){
 	long double left, right, T;
 	cin >> left >> right >> T;
	while (T--){
	 	int sign = 0;
	 	string s;
	 	cin >> s;
	 	//cout << s << "ldjkfhlashfso " << endl;
	 	if ((s[0] == '0' && s.size()>1) || (s[0] == '-' && s[1] == '0') || (s[0]=='-' && s.size() == 1))
	 		cout << 1 << endl;
	 	else if (s.size()>30)
	 		cout << 2 << endl;
	 	else{
	 		long double res = 0;
	 		if (s[0]=='-'){
		 		for (int i = 1; i< s.size(); i++)
	 				res = res*10+(s[i]-'0');
	 			res=res*-1.0;
			 }
			 else{
			 	for (int i = 0; i< s.size(); i++)
	 				res = res*10+(s[i]-'0');
			 }
			if(res>=left && res<=right)
			 	cout << 0 << endl;
			else
				cout << 2 << endl;
		}
	}
 }*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
 	long double left, right, T;
 	cin >> left >> right >> T;
 	if (T == 0){
 		return 0;
     }
     getchar();
     while (T--){
     	int sign = 0;
     	string s;
     	getline(cin, s);
     	//cout << s << s.size() << endl;
     	if ((s[0] == '0' && s.size()!=1) || (s[0] == '-' && s[1] == '0') || (s[0]=='-' && s.size() == 1))
     		sign=1;
     	else{
     		long double res = 0;
     		for (int i = 0; i< s.size(); i++){
     			if (s[i] == ' ' && i != s.size()-1)
     				sign=1;
     			if (s[i] != ' ' && s[i] != '-')
     				res = res*10+(s[i]-'0');
             }
             if(s[0] == '-')
             	res = res*-1.0;
            if(sign!=1 && res>=left && res<=right)
             	sign=0;
            else if(sign != 1 && (res < left || res > right))
                sign = 2;
            else if (sign != 1 && (s.size() > 30))
                sign = 2;
         }
         cout << sign << endl;
     }
 }
