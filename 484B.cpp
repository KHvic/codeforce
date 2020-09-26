#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cerr << *it << " = " << a << endl;
err(++it, args...);
}

int main()
{
    fastio
    int n, v;
    cin >> n;
    set<int> vals;
    int mx = 0;
    for(int i=0;i<n;i++) {
        cin >> v;
        mx = max(mx, v);
        vals.insert(v);
    }
    vector<int> largest(mx*2);
    for(int x : vals) largest[x] = x;
    for(int i=1;i<largest.size();i++) largest[i] = max(largest[i], largest[i-1]);

    int res = 0;
    // harmonic series
    for(int x : vals) {
        for(int j=2*x;j<2*mx;j+=x) res = max(res, largest[j-1] % x);
    }
    cout << res;
}
