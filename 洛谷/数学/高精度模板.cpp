#include <iostream>
#include <vector>
#include <string>
using namespace std; 
struct Big:vector<int> {
	Big(int n=0){
		push_back(n);
		check();
	}
	Big& check(){
		while(!empty()&&!back()) 
			pop_back();
		if(empty())
			return *this;
		for(int i=1; i<size(); i++){
			(*this)[i] += (*this)[i-1]/10;
			(*this)[i-1] %= 10;
		}
		while(back()>=10){
			push_back(back()/10);
			(*this)[size()-2] %= 10;
		}
		return *this;
	}
};
istream& operator >> (istream &in, Big &B){
	string s;
	in >> s;
	B.clear();
	for(int i=s.size()-1; i>=0; i--){
		B.push_back(s[i]-'0'); 
	}
	return in;
}
ostream& operator <<(ostream &out, const Big &B){
	if(B.empty()) out << 0;
	for(int i=B.size()-1; i>=0; i--){
		out << B[i];
	}
	return out;
}
Big operator *(const Big &a, const Big &b){
	Big B;
	B.assign(a.size()+b.size()-1, 0);
	for(int i=0; i!=a.size(); i++){
		for(int j=0; j!=b.size(); j++){
			B[i+j]+=a[i]*b[j];
		}
	}
	return B.check(); 
}
Big operator +(const Big &a, const Big &b){
	Big B;
	int n = max(a.size(), b.size());
	B.assign(n, 0);
	int m=min(a.size(), b.size());
	for(int i=0; i<m; i++)
		B[i]=a[i]+b[i];
	if(a.size() > b.size())	
		for(int i=n-1; i>=m; i--)
			B[i]+=a[i];
	else
	 	for(int i=n-1; i>=m; i--)
			B[i]+=b[i];
	return B.check();
}
int main(){
	Big a, b;
	cin >> a >> b;
//	cout << a*b ;
	cout << a+b;
	return 0;
}
