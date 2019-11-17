#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Date{
	int year, month, day;	
};
bool cmp(Date &a, Date &b){
	if (a.year == b.year ){
		if (a.month == b.month ){
			return a.day < b.day;
		}
		return a.month < b.month;
	}
	return a.year < b.year;
}
bool is_year(int y){
	return (y % 4 == 0 || (y % 100 == 0) && (y % 400 == 0));
}
bool judge(Date &a){
	int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (is_year(a.year ))
		mon[2] = 29;
	if(a.year < 1960 || a.year > 2059)
		return false;
	if (a.month < 1 || a.month > 12)
		return false;
	if (a.day < 1 || a.day > mon[a.month])
		return false;
}
void print(Date &a){
	printf("%d-%02d-%02d\n", a.year, a.month , a.day);
}
bool operator == (Date &a, Date &b){
	return (a.day == b.day && a.year == b.year && a.month == b.month);
}
int main(){
	vector<Date> date;
	int y, m, d;
	scanf("%d/%d/%d", &y,&m,&d);
	Date a;
	a.year = y+1900; a.month = m; a.day = d; date.push_back(a);
	a.year = y+2000; a.month = m; a.day = d; date.push_back(a);
	a.year = d+1900; a.month = m; a.day = y; date.push_back(a);
	a.year = d+2000; a.month = m; a.day = y; date.push_back(a);
	a.year = d+1900; a.month = y; a.day = m; date.push_back(a);
	a.year = d+2000; a.month = y; a.day = m; date.push_back(a);
	sort(date.begin() , date.end(), cmp);
	for (int i = 1; i < date.size(); i++){
		if (date[i] == date[i-1])
			date.erase(date.begin()+i--); 
	}
	for (int i= 0; i < date.size() ; i++){
		if (judge(date[i]))
			print(date[i]);
	}
	return 0;
}
