#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    string s;
    cin >> s;
    // place 0 at 1 1, 1 2, 1 3, 1 4 repetitively
    // place 1 at 3 1, 3 3 repetitively
    int idx0 = 0, idx1 = 0;
    for(char c : s) {
        if(c=='0') {
            cout << 1 << " " << (idx0 % 4) + 1 << "\n";
            idx0++;
        } else {
            cout << 3 << " " << (idx1%2 ? 3 : 1) << "\n";
            idx1++;
        }
    }
}
