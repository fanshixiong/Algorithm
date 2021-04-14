#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    while (n--) {
        ll w, g, h, r; // 注意数据范围,平方会爆int
        cin >> w >> g >> h >> r;
        // 求长度的最小值：l = min(g,h)，且人处于高度较低处
        double mi = sqrt((w * w) + (h - g) * (h - g));

        // 求长度的最大值: l = r,二分找出导数为0的点
        g = g - r;
        h = h - r;
        double L = 0, R = w;
        while (R - L > 1e-8) // 设置精度一般比题目要求多两位
        {
            double x = (R + L) / 2;
            double f = x / sqrt(g * g + x * x) - (w - x) / sqrt(h * h + (w - x) * (w - x));
            if (f < 0) L = x;
            else R = x;
        }
        // 带回原方程求解
        double ma = sqrt(g * g + L * L) + sqrt(h * h + (w - L) * (w - L));
        printf("%.8lf %.8lf\n", mi, ma);
    }
}