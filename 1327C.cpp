#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n, m, k, a, b;
    cin >> n >> m >> k;
    for(int i=0;i<2*k;i++) cin >> a >> b;

    cout << 2*(n-1) + (m-1) + n*(m-1) << "\n";
    cout << string(m-1, 'L') << string(n-1, 'U');
    for(int i=0;i<n;i++) {
        if(i) cout << "D";
        if(i%2) cout << string(m-1, 'L');
        else cout << string(m-1, 'R');
    }
}
