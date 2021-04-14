#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;
    ll sum = 0;
    for (int i = 0; i < s.length() - 1; i++)//枚举从s[i]为起始元素开始的每一个的情况
    {
        if (s[i] != s[i + 1])//当s[i+1]与s[i]相同时就直接跳到下一个。
        {
            int indc = 0;
            for (int j = i + 1; j < s.length(); j++)//向后枚举所有情况，看适不适合做末尾元素
            {
                if (indc >= 26)//小优化，当到达第27种元素的时候必然不能做末尾元素
                    break;
                if (s[j] == s[i])//当有与起始元素相同的元素时退出，
                {
                    break;
                }
                bool is = false;//标记s[j]是否在前面存在
                if (s[j] != s[j - 1])//当遇到连续的末尾元素时退出，不进入第三层循环
                {
                    for (int k = i + 1; k < j; k++)//找从i+1到j-1是否存在与s[j]相同的元素
                    {
                        if (s[k] == s[j])//存在与s[j]相同的元素就退出循环。
                        {
                            is = true;//存在
                            break;
                        }
                    }
                    if (!is)//不存在就满足好的序列，总数+1，且种类数+1
                    {
                        sum++;
                        indc++;
                    }
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}