#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

vector<int> bfs(vector<int>& mov) {
    vector<int> dist(10,1e8);
    queue<int> q;
    q.push(0);
    int steps = 0;
    while(!q.empty()) {
        for(int len=q.size();len>0;len--) {
            int top = q.front(); q.pop();
            for(int m : mov) {
                int nxt = (m+top)%10;
                if(dist[nxt] >= 1e8) {
                    dist[nxt] = steps;
                    q.push(nxt);
                }
            }
        }
        steps++;
    }
    return dist;
}

int main(){
    fastio
    string s;
    cin >> s;
    int transitions[10][10];
    memset(transitions, 0, sizeof transitions);
    vector<vector<vector<int>>> cost(10, vector<vector<int>>(10));
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            vector<int> mov = {i, j};
            cost[i][j] = bfs(mov);
        }
    }
    for(int i=0;i<s.size()-1;i++) {
        int v1 = s[i]-'0', v2 = s[i+1]-'0';
        transitions[v1][v2]++;
    }
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            ll sum = 0;
            for(int a=0;a<10;a++) {
                for(int b=0;b<10;b++) {
                    int diff = b-a;
                    if(diff<0) diff += 10;
                    int cnt = transitions[a][b];
                    sum += 1LL*cnt*cost[i][j][diff];
                }
            }
            cout << (sum >= 1e8 ? -1 : sum) << " \n"[j==9];
        }
    }
}
