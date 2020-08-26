#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// main idea is that we can always shift ) to the end
// ensure balance counter is always >= 0

int main(){
    fastio
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> res;
    for(char c : s) {
        if(c=='(') cnt++;
        else if(c==')') cnt--;
        else {
            cnt--;
            res.push_back(1); // greedy treat as )
        }
        if(cnt<0) {
            cout << -1; return 0;
        }
    }
    if(cnt>0 && res.empty()) {
        cout << -1; return 0;
    }
    if(cnt>0) res.back() += cnt; // assign all to the last #
    // validate new string is valid
    int idx = 0;
    cnt = 0;
    for(char c : s) {
        if(c=='(') cnt++;
        else if(c==')') cnt--;
        else cnt -= res[idx++];
        if(cnt<0) {
            cout << -1; return 0;
        }
    }

    for(int x : res) cout << x << "\n";
}
