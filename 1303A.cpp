#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        int first = s.find('1');
        int last = s.find_last_of('1');
        int res = count(s.begin()+first, s.begin()+last+1, '0');
        cout << res << "\n";
    }
}
