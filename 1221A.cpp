#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n, v;
    cin >> t;
    while(t--) {
        cin >> n;
        ll sum = 0;
        while(n--) {
            cin >> v;
            if(v <= 2048) sum += v;
        }
        cout << (sum >= 2048 ? "YES" : "NO") << "\n";
    }
}
