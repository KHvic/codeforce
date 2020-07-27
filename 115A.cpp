#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int compute_height(int x) {
    int res = 0;
    for(int child : graph[x]) {
        res = max(res, compute_height(child));
    }
    return res+1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, p;
    cin >> n;
    graph.assign(n,vector<int>());
    vector<int> roots;
    for(int i=0;i<n;i++) {
        cin >> p;
        if(p==-1) {
            roots.push_back(i);
            continue;
        }
        graph[--p].push_back(i);
    }
    int mxdepth = 0;
    for(int x : roots) mxdepth = max(compute_height(x), mxdepth);
    cout << mxdepth;
}
