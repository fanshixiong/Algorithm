#include <bits/stdc++.h>
using namespace std;
struct OP
{
    int pos;
    char op;
};
bool scanString(string str) {  //扫描括号是否匹配
        if(str=="")
            return false;
        stack<string> sta;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(')
                sta.push("(");
            if (str[i] == ')') {
                if (!sta.empty() && sta.top() == "(") {
                    sta.pop();
                    continue;
                }
                else
                    return false;
            }
        }
        if (sta.empty())
            return true;
        else
            return false;
    }
bool judgeString(string str)  //判断是否出现“）（”的情况
    {
        int i1=0; int i2=1;
        while(i2<str.length()){
            if(str[i1]==')'&&str[i2]=='(')
                return false;
            else
            {   i1++;
                i2++;
            }
        }
        return true;
    }
char * Remove(char * str)
{
    char * p = str;
    int i = 0;
    stack<OP> ops;
    vector<int> rems;
    while(*p!='\0')
    {
        OP op;
        if(*p=='+'||*p=='-'||*p=='*'||*p=='/'||*p=='(')
        {
            op.op =*p;
            op.pos = i;
            ops.push(op);
        }
        else if(*p==')')
        {
            int next = 0;
            int pre  = 0;
            int lower = 1;

            char * t = p+1;
            while(*t!='\0'&&*t==' ')
            {
                ++t;
            }
            next = (*t=='*'||*t=='/');

            while(ops.size()>0)
            {
                op = ops.top();
                ops.pop();
                if(op.op=='(')
                {
                    break;
                }
                if(op.op=='+'||op.op=='-')
                {
                    lower = 0;
                }
            }
            t =&str[op.pos] -1;
            while(t>=str&&*t==' ')
            {
                --t;
            }
            pre = (t>=str&&(*t=='*'||*t=='/'));

            if(lower>=pre&&lower>=next)
            {
                rems.push_back(i);
                rems.push_back(op.pos);
            }
        }
        ++i;
        ++p;
    }
    if(rems.size()==0)
    {
        return str;
    }
    sort(rems.begin(),rems.end());
    int cur = rems[0];
    int beg = rems[0] +1;
    for(int i = 0;i<rems.size()-1;++i)
    {
        int end = rems[i+1];
        while(beg<end)
        {
            str[cur]=  str[beg];
            ++beg;
            ++cur;
        }
        beg = end +1;
    }
    while(str[cur]!='\0')
    {
        str[cur]=  str[beg];
        ++cur;
        ++beg;
    }
    return str;
}

int main()
{   char str[256]= "((1)+(2/2)+(1*2)/2)";
    if(scanString(str)!=true||judgeString(str)!=true)
      cout<<"error!!"<<endl;
    else{

            cout<<Remove(str)<<endl;
    }
    return 0;
}
