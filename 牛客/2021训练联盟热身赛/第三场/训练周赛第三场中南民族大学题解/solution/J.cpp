#include<bits/stdc++.h>

using namespace std;
#define ll long long

double A[1000005];
double pre[1000005];
double suf[1000005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pre[i] = pre[i - 1] + A[i];//得到前缀和
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + A[i];//得到后缀和
    }
    double max1 = 0;//初始化max1，当前缀和与后缀和的平均值都小于0时取0

    for (int i = 1; i <= n; i++) {
        max1 = max(max1, pre[i] / i);//求前缀最大平均值
        max1 = max(max1, suf[i] / (n - i + 1));//求后缀最大平均值
    }
    printf("%.9lf\n", max1);//输出为小数点后9位
}