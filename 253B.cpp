#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, v;
    cin >> n;
    vector<int> cnt(5001);
    for(int i=0;i<n;i++) {
        cin >> v;
        cnt[v]++;
    }
    for(int i=1;i<5001;i++) cnt[i] += cnt[i-1];
    int res = n;
    for(int i=1;i*2<5001;i++) {
        int total = cnt[2*i] - cnt[i-1];
        int cost = n - total;
        res = min(res, cost);
    }
    cout << res;
}
