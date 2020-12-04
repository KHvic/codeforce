#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, x, y;
    cin >> t;
    while(t--) {
        cin >> x >> y;
        if(y>x) swap(x, y);
        int cost = x+y;
        int need = max(x-1-y, 0);
        cost += need;
        cout << cost << "\n";
    }
}
