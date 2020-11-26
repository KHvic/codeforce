#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t;
    double n, d;
    cin >> t;
    while(t--) {
        cin >> n >> d;
        // notice we can move ceil function out because a + ceil(b) = ceil(a+b) for any two integer a,b
        // derivative of x + d/(x+1) => 1 + d/(x+1)^2
        // solve when dy/dx = 0, x = sqrt(d) - 1
        double x = sqrt(d) - 1.0;
        double fx = ceil(x + d/(x+1.0));
        cout << (fx <= n ? "YES" : "NO") << "\n";
    }
}
