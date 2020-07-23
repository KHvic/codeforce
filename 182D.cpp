#include <bits/stdc++.h>
using namespace std;
#define ll long long

// KMP allow us to find shortest prefix that is repeated in a string
string shortestPrefix(string& s) {
    int n = s.size();
    vector<int> backtable(n+1);
    backtable[0] = -1;
    int i=0, j=-1;
    while(i<n) {
        while(j>=0 && s[j] != s[i]) j = backtable[j];
        backtable[++i] = ++j;
    }
    int cycle = n-j;
    if(n%cycle) return s; // divisor
    return s.substr(0, cycle);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    string shortestA = shortestPrefix(a), shortestB = shortestPrefix(b);
    if(shortestA!=shortestB) cout << "0";
    else {
        int cntA = a.size() / shortestA.size();
        int cntB = b.size() / shortestB.size();
        int gcd = __gcd(cntA, cntB);
        // number of common divisors of a and b
        // is number of divisors of their gcd
        unordered_set<int> divisors;
        for(ll i=1;i*i<=gcd;i++) {
            if(gcd%i == 0) {
                divisors.insert(i);
                divisors.insert(gcd/i);
            }
        }
        cout << divisors.size();
    }
}
