#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n,v;
    cin >> n;
    set<int> vals;
    set<int> prevs;
    while(n--) {
        set<int> nxt;
        cin >> v;
        for(int x : prevs) nxt.insert(x | v);
        nxt.insert(v);
        for(int x : nxt) vals.insert(x);
        prevs = nxt;
    }
    cout << vals.size();
}
