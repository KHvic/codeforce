#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int cost[26];
    for(int i=0;i<26;i++) cin >> cost[i];
    string s;
    cin >> s;
    // count of 'pairs' with sum = 0
    map<ll, ll> cnt[26];
    ll sum = 0, res = 0;
    for(char c : s) {
        res += cnt[c-'a'][sum];
        sum += cost[c-'a'];
        cnt[c-'a'][sum]++;
    }
    cout << res;
}
