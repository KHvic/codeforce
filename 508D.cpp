#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

map<string, vector<string>> graph;
map<string, int> indegree, outdegree;

deque<string> res;

void hierholzer(string x) {\
    while(graph[x].size()) {
        string nxt = graph[x].back(); graph[x].pop_back();
        hierholzer(nxt);
    }
    res.push_front(x);
}

int main(){
    fastio
    int n;
    string s;
    cin >> n;
    set<string> ss;
    for(int i=0;i<n;i++) {
        cin >> s;
        string a = s.substr(0,2), b = s.substr(1);
        graph[a].push_back(b);
        indegree[b]++;
        outdegree[a]++;
        ss.insert(a); ss.insert(b);
    }
    string start = graph.begin()->first;;
    int cntUnequal = 0;
    bool ok = true;
    // check euler path/circuit
    for(auto& v : ss) {
        int diff = indegree[v] - outdegree[v];
        if(diff == -1) start = v; // potential source in circuit
        if(diff != 0) cntUnequal++; // at most 2 of these node, source/sink
        if(abs(diff) >= 2) ok = false; // max diff in euler circuit is 1
    }
    ok &= cntUnequal <= 2;
    if(!ok) {
        cout << "NO"; return 0;
    }

    hierholzer(start);
    // check all visited
    for(auto& p :graph)
        if(!p.second.empty()) ok = false;

    if(ok) {
        cout << "YES\n";
        s = "";
        for(int i=0;i<res.size();i++)
            if(i==0) s += res[i];
            else s += res[i].substr(1);
        cout << s;
    } else {
        cout << "NO";
    }
}
