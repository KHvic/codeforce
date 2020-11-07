#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int, char> pp;

int main(){
    fastio
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        map<char, int> cnt;
        for(char c : s) cnt[c]++;
        vector<pp> vals = {{cnt['R'], 'P'}, {cnt['S'], 'R'}, {cnt['P'], 'S'}};
        sort(vals.rbegin(), vals.rend());
        cout << (string(s.size(), vals[0].second)) << "\n";
    }
}
