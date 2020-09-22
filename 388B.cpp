#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int k;
    cin >> k;
    int depth = ceil(log2(k));
    vector<vector<int>> graph; // by depth
    graph.push_back({0});
    int i=1,idx=2;
    while(i*2<=k) {
        graph.push_back({idx,idx+1,idx+2});
        idx+=3;
        i*=2;
    }
    k -= i;
    graph.push_back({1});
    vector<string> res(idx, string(idx, 'N'));
    // connect depth
    for(int i=0;i<graph.size()-1;i++) {
        for(int j=0;j<min(2, (int)graph[i].size());j++) {
            for(int k=0;k<(i+1==graph.size()-1 ? 1 : 2);k++) {
                int a = graph[i][j], b = graph[i+1][k];
                res[a][b] = res[b][a] = 'Y';
            }
        }
        if(graph[i].size() == 3) {
            int a = graph[i].back(), b = graph[i+1].back();
            res[a][b] = res[b][a] = 'Y';
        }
    }
    for(int i=0;i<32;i++) {
        if(k & (1<<i)) {
            for(int j=0;j<min(2, (int)graph[i].size());j++) {
                int a = graph[i][j], b = graph[i+1].back();
                res[a][b] = res[b][a] = 'Y';
            }
        }
    }
    cout << res.size() << "\n";
    for(int i=0;i<res.size();i++) cout << res[i] << "\n";
}
