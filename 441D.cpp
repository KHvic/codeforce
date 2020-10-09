#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> nxt;
vector<bool> vis;

inline void cycle(int x) {
    for(int i=x;!vis[i];i=nxt[i]) vis[i] = true;
}

int main()
{
    fastio
    int n, m;
    cin >> n;
    vis = vector<bool>(n);
    nxt = vector<int>(n);
    for(int i=0;i<n;i++) cin >> nxt[i], --nxt[i];
    cin >> m;
    int numComponents = 0;
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            numComponents++;
            cycle(i);
        }
    }
    int targetComponents = n - m; // for each m, we merge two component
    cout << abs(numComponents-targetComponents) << "\n";
    if(numComponents < targetComponents) {
        for(int i=0;i<n&&numComponents<targetComponents;i++) {
            vector<int> cyclePos(n, -1);
            for(int j=nxt[i],p=0;j!=i;j=nxt[j]) {
                cyclePos[j] = p++;
            }
            // when we swap, we break the component into two parts
            for(int j=i+1,p=0;j<n&&numComponents<targetComponents;j++) // pick smallest available lexicographically
            if(cyclePos[j] >= p) { // only can pick item after p
                swap(nxt[j], nxt[i]);
                cout << (i+1) << " " << (j+1) << " ";
                p = cyclePos[j]+1;
                numComponents++;
            }
        }
    }
    if(numComponents > targetComponents) {
        // merge components by merging components
        vis.assign(n, false);
        cycle(0);
        for(int i=1;i<n&&numComponents>targetComponents;i++) {
            if(!vis[i]) {
                cycle(i);
                numComponents--;
                cout << 1 << " " << (i+1) << " ";
            }
        }
    }

}
