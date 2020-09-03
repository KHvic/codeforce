#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int,int> pii;

vector<pii> constructKGraph(int len, int offset) {
    vector<pii> edges;
    // item 0 will only have k-1 edges for connecting to the other component
    for(int i=1;i<len-2;i++) edges.emplace_back(offset, i+offset);

    for(int i=1;i<len-2;i++) {
        for(int j=i+1;j<len-2;j++) {
            if((i-1)/2 == (j-1)/2) continue;
            edges.emplace_back(i+offset, j+offset);
        }
        edges.emplace_back(i+offset, len-2+offset);
        edges.emplace_back(i+offset, len-1+offset);
    }
    edges.emplace_back(len-1+offset, len-2+offset);
    return edges;
}

int main(){
    fastio
    int k;
    cin >> k;
    // no possible result when k is even
    // proof 1. Euler path exist, therefore no bridge
    // proof 2. handshake lemma, removing an edge for one of the connected component
    // result in K*(N-1)+(K-1) total degree, not an even degree indicating invalid graph
    if(k%2==0) {
        cout << "NO"; return 0;
    }
    cout << "YES\n";
    if(k==1) {
        printf("2 1\n1 2\n");
        return 0;
    }
    // create two components of k+2 size
    int n = k+2;
    vector<pii> component1 = constructKGraph(n, 1), component2 = constructKGraph(n, n+1);
    component1.emplace_back(1, n+1);
    cout << n*2 << " " << component1.size() + component2.size() << "\n";
    auto print = [](auto com) {
        for(auto& p : com) cout << p.first << " " << p.second << "\n";
    };
    print(component1);
    print(component2);
}
