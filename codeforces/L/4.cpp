#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> G[102];
    struct node{
        int id;
        int step;
        node(int id, int step):id(id), step(step){}
    };
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        for(int i=0; i<n; i++){
            int t = friends[i].size();
            for(int j=0; j<t; j++){
                int v = friends[i][j];
                G[i].push_back(v);
                G[v].push_back(i);
            }
        }
        int vis[n+1];
        int flg[n+1];
        queue<node> q;
        q.push(node(id, 0));
        vis[id] = 1;
        while(!q.empty()){
            node t=q.front();
            q.pop();
            if(t.step == level){
                flg[t.id] = 1;
            }
            for(int i=0; i<G[t.id].size(); i++){
                int v=G[t.id][i];
                if(!vis[v]){
                    q.push(node(v, t.step+1));
                }
            }
        }
        vector<pair<string, int> > cnt;
        map<string, int> mp;
        for(int i=0; i<n; i++){
            if(!flg[i])
                continue;
            for(int j=0; j<watchedVideos[i].size(); j++){
                mp[watchedVideos[i][j]]++;
            }
        }
        for(int i=0; i<n; i++){
            if(!flg[i])
                continue;
            for(int j=0; j<watchedVideos[i].size(); j++){
                if(mp[watchedVideos[i][j]]){
                    cnt.push_back(make_pair(watchedVideos[i][j], mp[watchedVideos[i][j]]));
                    mp[watchedVideos[i][j]] = 0;
                }
            }
        }
        sort(cnt.begin(), cnt.end());
        vector<string> ans;
        for(int i=0; i<cnt.size(); i++){
            ans.push_back(cnt[i].first);
        }
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    Solution 
    return 0;
}