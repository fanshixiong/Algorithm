#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定年份和月份，按照输出当月日历
     * @param year int 年份
     * @param month int 月份(1-12)
     * @param dayOfWeek int 当月1号是星期几，1表示星期一，7表示星期天
     * @return stringvector<vector<>>
     */
    bool isLeapYear(int year){
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return true;
        return false;
    }
    vector<vector<string> > calendar(int year, int month, int dayOfWeek) {
        // write code here
        vector<vector<string> > ans;
        vector<string> v;
        for(int i = 1; i < dayOfWeek; i++) v.push_back("");
        int cnt = 0;
        for(int i = dayOfWeek; i <= 7; i++) v.push_back(to_string(++cnt));
        
        ans.push_back(v);
        if(month == 2){
            if(isLeapYear(year)){
                if(dayOfWeek == 1){
                    for(int i = 1; i <= 3; i++){
                        vector<string> s;
                        for(int j = 0; j < 7 && cnt < 29; j++) s.push_back(to_string(++cnt));
                        while((int)s.size() && (int)s.size() < 7) s.push_back(""); 
                        ans.push_back(s);
                    }
                }else{
                    for(int i = 1; i <= 4; i++){
                        vector<string> s;
                        for(int j = 0; j < 7 && cnt < 29; j++) s.push_back(to_string(++cnt));
                        while((int)s.size() && (int)s.size() < 7) s.push_back(""); 
                        ans.push_back(s);
                    }
                }
            }else{
                for(int i = 1; i <= 4; i++){
                    vector<string> s;
                    for(int j = 0; j < 7 && cnt < 28; j++) s.push_back(to_string(++cnt));
                    while((int)s.size() && (int)s.size() < 7) s.push_back("");  
                    ans.push_back(s);
                }
            }
            return ans;
        }
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            for(int i = 1; i <= 5; i++){
                vector<string> s;
                for(int j = 0; j < 7 && cnt < 31; j++) s.push_back(to_string(++cnt));
                while((int)s.size() && (int)s.size() < 7) s.push_back(""); 
                if(s.size()) ans.push_back(s);
            }
        }
        else{
            for(int i = 1; i <= 5; i++){
                vector<string> s;
                for(int j = 0; j < 7 && cnt < 30; j++) s.push_back(to_string(++cnt));
                while((int)s.size() && (int)s.size() < 7) s.push_back(""); 
                if(s.size())ans.push_back(s);
            }
        }
        return ans;
    }
};
int main(){
	Solution *s = new Solution();
	vector<vector<string> > ans = s -> calendar(2100, 4, 1);
	for(auto c : ans){
		for(auto str : c){
			cout << str << " ";
		}
		cout << endl;
	}
	return 0;
}