#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<ll, ll> ii;

int main(){
    fastio
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        vector<int> vals;
        for(int i=0,cur=0;i<n;i++) {
            cur++;
            if(i==n-1 || s[i] != s[i+1]) {
                vals.push_back(cur);
                cur = 0;
            }
        }
        int res = 0, ones = 0;
        for(int x : vals) {
            ones++;
            int take = min(x-1, ones);
            res += take;
            ones -= take;
        }
        res += (ones+1)/2;
        cout << res << "\n";
    }
}
