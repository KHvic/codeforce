#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    fastio
    string s;
    cin >> s;
    vector<int> z = z_function(s);
    int n = s.size();
    vector<int> count(n+1);
    vector<bool> prefix_suffix(n+1);
    for(int i=0;i<n;i++) {
        if(z[i] == 0) continue;
        if(i+z[i] == n) prefix_suffix[z[i]] = true;
        count[z[i]]++;
    }
    prefix_suffix[n] = true;
    count[n] = 1;
    int res = 1;
    for(int i=n-1;i>0;i--) {
        count[i] += count[i+1];
        if(prefix_suffix[i]) res++;
    }
    cout << res << "\n";
    for(int i=1;i<=n;i++) {
        if(prefix_suffix[i]) cout << i << " " << count[i] << "\n";
    }
}
