#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// k*total + prefix[i] = x, where total is sum of string
// k = (x-prefix)/total, just check if k exist for this index

int main(){
    fastio
    int t, n, x;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> x >> s;
        vector<int> val;
        int sum = 0;
        for(char c : s) {
            sum += c == '0' ? 1 : -1;
            val.push_back(sum);
        }

        ll res = 0;
        if(sum == 0) {
            bool contain = find(val.begin(), val.end(), x) != val.end();
            res = contain ? -1 : 0;
        } else {
            int total = val.back();
            if(x == 0) res++; // empty prefix is also one
            for(int v : val)
                if(((x-v) % total) == 0 && ((x-v)/total) >= 0) res++;
        }
        cout << res << "\n";
    }
}
