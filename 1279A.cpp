#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    cin >> t;
    vector<ll> vals(3);
    while(t--) {
        cin >> vals[0] >> vals[1] >> vals[2];
        sort(vals.begin(), vals.end());
        int need = vals.back() -1;
        cout << (vals[0] + vals[1] >= need ? "Yes" : "No") << "\n";
    }
}
