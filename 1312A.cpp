#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << (n%m == 0 ? "YES" : "NO") << "\n";
    }
}
