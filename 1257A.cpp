#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n, x, a, b;
    cin >> t;
    while(t--) {
         cin >> n >> x >> a >> b;
         if(a>b) swap(a, b);
         int mx = min(n-b + a-1, x);
         cout << (b-a) + mx << "\n";
    }
}
