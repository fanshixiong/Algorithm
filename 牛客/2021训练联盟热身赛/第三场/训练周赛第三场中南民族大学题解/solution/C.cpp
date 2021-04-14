#include <bits/stdc++.h>

using namespace std;

#define N 1005

int main() {
    int p, d, district;    //p:选举 ， d:地区 ， district: 地区编号
    long long a[N] = {0}, b[N] = {0}, ra, rb, sum = 0;
    cin >> p >> d;
    for (int i = 0; i < p; ++i) {
        cin >> district >> ra >> rb;
        a[district] += ra;
        b[district] += rb;
        sum = sum + ra + rb;
    }
    double rate = 1.0;
    ra = rb = 0;
    for (int i = 1; i <= d; ++i) {
        if (a[i] > b[i]) {
            cout << "A " << a[i] - (a[i] + b[i]) / 2 - 1 << " " << b[i] << "\n";
            rb += b[i];
            ra = ra + a[i] - (a[i] + b[i]) / 2 - 1;
        } else {
            cout << "B " << a[i] << " " << b[i] - (a[i] + b[i]) / 2 - 1 << "\n";
            ra += a[i];
            rb = rb + b[i] - (a[i] + b[i]) / 2 - 1;
        }
    }
    rate = rate / sum * abs(ra - rb);
    printf("%.10f\n", rate);
    return 0;
}