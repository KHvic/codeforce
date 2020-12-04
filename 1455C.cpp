#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t;
    int a, b;
    cin >> t;
    while(t--) {
        // to maximize my score, I let opponents always win when he serve
        // then I win all remaining
        cin >> a >> b;
        a = max(a-1, 0); // first player always win 1 less
        cout << a << " " << b << "\n";
    }
}
