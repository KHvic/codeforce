#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// consider invalid string
// all string fulfill condition except 
// substring with only 1 of some character & this character is on the side

int main(){
    fastio
    int n;
    string s;
    cin >> n >> s;
    vector<int> previous(n), next(n);
    int lastA=-1,lastB=-1;
    for(int i=0;i<n;i++) {
        if(s[i]=='A') {
            previous[i] = lastA+1;
            lastA = i;
        } else {
            previous[i] = lastB+1;
            lastB = i;
        }
    }
    lastA = n, lastB = n;
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='A') {
            next[i] = lastA-1;
            lastA = i;
        } else {
            next[i] = lastB-1;
            lastB = i;
        }
    }
    ll res = 1LL*n*(n+1)/2;
    for(int i=0;i<n;i++) {
        if(i && s[i-1] != s[i]) res++; // double count
        int len = next[i] - previous[i] + 1;
        res -= len;
    }
    cout << res << "\n";
}
