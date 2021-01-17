#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;

const int N = 310;

struct Person
{
    int chinese, math, english;
    int total;
    int id;
    bool operator< (const Person& W)const
    {
        if (total != W.total) return total > W.total;
        if (chinese != W.chinese) return chinese > W.chinese;
        return id < W.id;
    }
}person[N];

void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i ++){
        int chinese, math, english;
        cin >> chinese >> math >> english;
        int total = chinese + math + english;
        person[i] = {chinese, math, english, total, i};
    }

    sort(person + 1, person + 1 + n);

    for (int i = 1; i <= 5; i ++ ) cout << person[i].id << " " << person[i].total << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}