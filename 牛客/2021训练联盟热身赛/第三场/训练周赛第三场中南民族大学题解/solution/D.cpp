#include <bits/stdc++.h>
using namespace std;

bool b[200];
int main()
{
    int n, x, a = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a = max(a, x);
        b[x] = 1;    //标记出现过的数字
    }
    if (a == n)
    {
        cout << "good job" << endl;
    }
    else
    {
        for (int i = 1; i <= a; i++)
            if (!b[i])
                cout << i << endl;
    }
    return 0;
}