#include<bits/stdc++.h>
using namespace std;
int q, n, k;


int main(){
    ios_base::sync_with_stdio(0);
    cin >> q;
    while(q--){
        vector<int> pos;
        string s;
        cin >> n >> k;
        cin >> s;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0')
                pos.push_back(i);
        }
        //for(int i=0; i<pos.size(); i++)
        //    cout << pos[i] << " ";
        //cout << endl;
        int position=0, i;
        for(i=0; i<pos.size() && k>0; i++){
            while(pos[i]==position){
                position++;
                i++;
            }
            if(k>=pos[i]-position){
                k-=(pos[i]-position);
                s[pos[i]]='1';
                s[position]='0';
                pos[i]=position;
                position++;
            }
            else
            {
                break;
            }
            
        }
        if(k && i<pos.size()){
            s[pos[i]]='1';
            s[pos[i]-k]='0';
        }
        cout << s << endl;
    }
    return 0;
}