#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    string x, y;
    cin >> x >> y;
    for(int i = 0; i < (int)x.size(); i++) 
        if(x[i] != y[i]) {
            for(int j = i; j <= i+1; j++) 
                x[j] = '*' + ('o' - x[j]);
            ans++;
        }
    cout << ans << endl;
    return 0;
}