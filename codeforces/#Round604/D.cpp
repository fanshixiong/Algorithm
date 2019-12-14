#include<bits/stdc++.h>
using namespace std;
/*
int main(){
    ios_base::sync_with_stdio(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool flg=0;
    string res;
    int a1 = b-a;
    if(a1 < 0){
        cout << "NO" << endl;
        return;
    }
    res += '5'; // flag
    b = a1;
    int cnt=a;
    while(cnt){
        res += "01";
        cnt--;
    }
    c--;
    if(c)
        res += '2';
    int b1 = c-b;
    if(b1 == -1){
        res[0] = '1';
        flg=1;
        b1++;
    }
    if(b1 < 0){
        cout << "NO" << endl;
        return;
    }
    c = b1;
    cnt = b;
    while(cnt){
        res+="12";
        cnt--;
    }
    d--;
    if(d)
        res += '3'
    int c1 = d-c;
    if(c1 == -2 && !flg){
        res[res.size()-2] = '3';
        c1++;
    }
    if(c1 < -1){
        cout << "NO" << endl;
        return;
    }
    cnt = c;
    while(cnt){

        cnt--;
    }
    return 0;
}
*/
int main(){
    ios_base::sync_with_stdio(0);
    deque<int> dq;
    int a[4];
    int n=0;
    for(int i=0; i<4; i++){
        cin >> a[i];
        n += a[i];
    }
    for(int j=0; j<n; j++){
        for(int i=0; i<4; i++){
            if(a[i]<=0) continue;
            if(dq.empty() || abs(i-dq.back()) == 1){
                a[i]--;
                dq.push_back(i);
                break;
            }
            if(dq.empty() || abs(i-dq.front()) == 1){
                a[i]--;
                dq.push_front(i);
                break;
            }
        }
    }
    if(dq.size() < n){
        cout << "NO" <<endl;
    }
    else{
        cout <<"YES" << endl;
        for(auto s:dq){
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}