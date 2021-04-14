#include<bits/stdc++.h>

using namespace std;

stack<int> s;
map<char, int> m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, ans, v1, v2;
    char value, op;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        m['A' + i] = (value == 'T') ? 1 : 0;  //根据输入对字母的值进行初始化
    }
    while (cin >> op) {
        if (isalpha(op))  //输入为字母，则其值入栈
            s.push(m[op]);
        else if (op == '+')  //输入为或运算
        {
            v1 = s.top(); //取出栈顶元素v1
            s.pop();
            v2 = s.top();  //取出栈顶元素v2
            s.pop();
            if (v1 == 1 || v2 == 1)  //对v1,v2进行或运算
                ans = 1;
            else
                ans = 0;
            s.push(ans);  //将运算结果入栈
        } else if (op == '*')  //输入为与运算
        {
            v1 = s.top();  //取出栈顶元素v1
            s.pop();
            v2 = s.top();  //取出栈顶元素v2
            s.pop();
            if (v1 == 1 && v2 == 1)  //对v1,v2进行或运算
                ans = 1;
            else
                ans = 0;
            s.push(ans);  //将运算结果入栈
        } else  //输入为非运算
        {
            v1 = s.top();  //取出栈顶元素v1
            s.pop();
            if (v1 == 1)  //对v1进行非运算，即取反
                ans = 0;
            else
                ans = 1;
            s.push(ans);  //将运算结果入栈
        }
    }
    if (s.top())  //当全部输入处理完毕后，栈中所剩的唯一元素即是表达式的值
        cout << "T" << endl;
    else
        cout << "F" << endl;
    return 0;
}