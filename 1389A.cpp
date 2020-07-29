
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin >> t;
    ll l, r;
    while(t--) {
        cin >> l >> r;
        ll l2 = l*2;
        if(l2>r) {
            cout << "-1 -1\n";
        } else {
            cout << l << " " << l2 << "\n";
        }
    }
}
