#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<ll,ll> ii;

ll crossProd(ii a, ii b, ii c) {
    return (b.first-a.first)*(c.second-b.second) - (c.first-b.first)*(b.second-a.second);
}

vector<int> depth;
vector<vector<int>> jump;
int mxlog;

int lca(int x, int y) {
    if(depth[y] > depth[x]) swap(x, y);
    int diff = depth[x] - depth[y];
    for(int i=0;i<=mxlog;i++)
        if(diff&(1<<i))
            x = jump[x][i];
    if(x==y) return x;
    for(int i=mxlog;i>=0;i--)
        if(jump[x][i] != jump[y][i])
            x = jump[x][i], y = jump[y][i];
    return jump[x][0];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,x,y,m;
    cin >> n;
    mxlog = log2(n+1);
    depth = vector<int>(n);
    jump = vector<vector<int>>(n, vector<int>(mxlog+1));
    vector<ii> pts(n);
    for(int i=0;i<n;i++) cin >> pts[i].first >> pts[i].second;

    // graham scan
    vector<int> st;
    for(int i=n-1;i>=0;i--) {
        while(st.size()>=2 && crossProd(pts[st[st.size()-2]], pts[st.back()], pts[i]) < 0) {
            st.pop_back();
        }
        if(i<n-1) {
            jump[i][0] = st.back();
            depth[i] = depth[st.back()]+1;
        } else jump[i][0] = n-1;
        st.push_back(i);
    }

    // build jump table
    for(int i=1;i<=mxlog;i++)
        for(int j=0;j<n;j++)
            jump[j][i] = jump[jump[j][i-1]][i-1];
    cin >> m;
    for(int i=0;i<m;i++) {
        cin >> x >> y; x--; y--;
        cout << lca(x, y)+1 << "\n";
    }
}
