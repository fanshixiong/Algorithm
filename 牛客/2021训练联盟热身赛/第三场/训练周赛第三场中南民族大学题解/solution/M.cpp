#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    while (n--) {
        ll w, g, h, r; // ע�����ݷ�Χ,ƽ���ᱬint
        cin >> w >> g >> h >> r;
        // �󳤶ȵ���Сֵ��l = min(g,h)�����˴��ڸ߶Ƚϵʹ�
        double mi = sqrt((w * w) + (h - g) * (h - g));

        // �󳤶ȵ����ֵ: l = r,�����ҳ�����Ϊ0�ĵ�
        g = g - r;
        h = h - r;
        double L = 0, R = w;
        while (R - L > 1e-8) // ���þ���һ�����ĿҪ�����λ
        {
            double x = (R + L) / 2;
            double f = x / sqrt(g * g + x * x) - (w - x) / sqrt(h * h + (w - x) * (w - x));
            if (f < 0) L = x;
            else R = x;
        }
        // ����ԭ�������
        double ma = sqrt(g * g + L * L) + sqrt(h * h + (w - L) * (w - L));
        printf("%.8lf %.8lf\n", mi, ma);
    }
}