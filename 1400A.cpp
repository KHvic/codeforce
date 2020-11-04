#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        string res;
        for(int i=0;i<n;i++) {
            res += s[i+i];
        }
        cout << res << "\n";
    }
}
