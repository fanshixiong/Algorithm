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
int strTint(char h1,char h2,char m1,char m2,char s1,char s2){
    cout<<h1<<h2<<" "<<s1<<s2<<endl;
    int hts=((h1-'0')*10+(h2-'0'))*3600;
    int mts=((m1-'0')*10+(m2-'0'))*60;
    int sec=hts+mts+((s1-'0')*10+(s2-'0'));
    cout<<hts<<" "<<mts<<" "<<sec<<endl;
    return sec;
}
//int to string  &  display
int intTstr(int t){
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
        t1s=strTint(str[0],str[1],str[3],str[4],str[6],str[7]);
        t1e=strTint(str[9],str[10],str[12],str[13],str[15],str[16]);
        if(str[19]=='+'){
            t1e+=(str[20]-'0')*(3600*24);
        }
        t1=t1e-t1s;
        cout<<t1<<endl;
        init();
        gets(str);
        t2s=strTint(str[0],str[1],str[3],str[4],str[6],str[7]);
        t2e=strTint(str[9],str[10],str[12],str[13],str[15],str[16]);
        if(str[19]=='+'){
            t2e+=(str[20]-'0')*(3600*24);
        }
        t2=t2e-t2s;
        cout<<t2<<endl;
        final=(t2+t1)/2;
        cout<<final<<endl;
        intTstr(final);
    }
}
