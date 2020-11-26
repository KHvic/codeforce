#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

pair<ll, bool> getLen(vector<ll>& prefix) {
    auto mxLast = max_element(prefix.rbegin(), prefix.rend());
    auto mxFirst = max_element(prefix.begin(), prefix.end());
    auto mnFirst = min_element(prefix.begin(), prefix.end());
    auto mnLast = min_element(prefix.rbegin(), prefix.rend());
    int pos = prefix.rend() - mxLast - 1, pos2 = mnFirst - prefix.begin();
    int pos3 = prefix.rend() - mnLast - 1, pos4 = mxFirst - prefix.begin();
    ll len = *mxLast - *mnFirst + 1;

    // can reduce if first min after all max, reaason is if you place it in between max, it increase the max
    // same logic for reducing max, check if any of these criteria is fulfilled
    return {len, (len>2 && (pos<pos2 || pos3 < pos4))};
}

int main(){
    fastio
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        string hori, vert;
        for(char c : s) {
            if(c=='W' || c=='S') vert += c;
            else hori += c;
        }
        vector<ll> prefixH(1, 0), prefixV(1, 0);
        for(char c : hori) {
            prefixH.push_back(prefixH.back() + (c=='A'?-1:1));
        }
        for(char c : vert) {
            prefixV.push_back(prefixV.back() + (c=='S'?-1:1));
        }
        auto len1 = getLen(prefixH), len2 = getLen(prefixV);
        ll res = len1.first * len2.first;
        if(len1.second) res = min((len1.first-1)*len2.first, res);
        if(len2.second) res = min((len2.first-1)*len1.first, res);
        cout << res << "\n";
    }
}
