#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

class FenwickTree {
private: vector<int> ft;
public:
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }
    int rsq(int b) {
        b++;
        int sum = 0;
        for (; b; b -= (b&-b)) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b) {
        return rsq(b) - rsq(a-1);
    }
    void adjust(int k, int v) {
        k++;
        for (; k < (int)ft.size(); k += (k&-k)) ft[k] += v;
    }
};


int main(){
    fastio
    int t, n;
    string s;

    cin >> n >> s;
    string cpy = s;
    queue<int> q[26];
    for(int i=0;i<n;i++) {
        int idx = s[i] - 'a';
        q[idx].push(i);
    }
    reverse(cpy.begin(), cpy.end());
    FenwickTree ft(n);
    ll res = 0;
    for(int i=0;i<n;i++) {
        int idx = cpy[i]-'a';
        int pos = q[idx].front(); q[idx].pop();
        res += pos - ft.rsq(pos);
        ft.adjust(pos, 1);
    }
    cout << res << "\n";
}
