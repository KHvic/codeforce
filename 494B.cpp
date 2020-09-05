#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll mod = 1e9+7;

string s,t;

vector<int> preprocess() {
    vector<int> bt(t.size()+1);
    int i=0,j=-1;
    bt[0] = -1;
    while(i<t.size()) {
        while(j>=0 && t[j] != t[i]) j = bt[j];
        bt[++i] = ++j;
    }
    return bt;
}

int main(){
    fastio
    cin >> s >> t;
    int n = s.size();
    // kmp
    auto bt = preprocess();
    vector<bool> isgood(s.size());
    int i=0,j=0;
    while(i<s.size()) {
        while(j>=0 && t[j] != s[i]) j = bt[j];
        j++;
        if(j==t.size()) {
            isgood[i] = true;
            j = bt[j];
        }
        i++;
    }

    vector<ll> ways(n); // num ways to partition ending at i
    vector<ll> sumWays(n), sumOfSumWays(n);
    for(int i=0;i<n;i++) {
        if(isgood[i]) {
            ll newstr = (i+1)-t.size()+1; // single new string
            ways[i] += newstr;
            // say we choose s[x..i]
            // we should add sum of ways[0] to ways[x-1]
            // foreach j= 0 to x-1 <= all string ending at i
            //   foreach k= 0 to j <= all possible ways of previous partitions
            //     ways[i] += ways[k]
            // we can do this in O(1) by cumulating the result (sumOfSumWays)
            int prev = i-t.size();
            if(prev >= 0) {
                ways[i] += sumOfSumWays[i-t.size()];
            }
            ways[i] %= mod;
        } else {
            ways[i] = i==0 ? 0 : ways[i-1];
        }
        sumWays[i] = (i==0 ? 0 : sumWays[i-1]) + ways[i];
        sumWays[i] %= mod;
        sumOfSumWays[i] = (i==0 ? 0 : sumOfSumWays[i-1]) + sumWays[i];
        sumOfSumWays[i] %= mod;
    }
    cout << sumWays[n-1] << "\n";
}
