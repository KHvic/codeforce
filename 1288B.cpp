#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// a+b+ab = a*10^len(b) + b
// b = 10^len(b) - 1, b is in the format of 9,99,999...
// count of such possible b is log10(b+1), number of digits in b+1

int main(){
    fastio
    int t;
    ll a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << (ll)(a*floor(log10(b+1))) << "\n";
    }
}
