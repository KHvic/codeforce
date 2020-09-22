#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 8002;
int cnt[MAXN];

bool clearable() {
    int cur = 0;
    for(int i=0;i<MAXN;i++) {
        cur += cnt[i];
        cur = max(cur, 0);
    }
    return cur == 0;
}

int main()
{
    fastio
    int n, m, v;
    string s;
    cin >> n >> m;
    vector<int> def, atk, ciel;
    multiset<int> cards;
    for(int i=0;i<n;i++) {
        cin >> s >> v;
        if(s=="ATK") atk.push_back(v);
        else {
            def.push_back(v); v++; // need additional atk point to clear def card
        }
        cnt[v]++;
    }
    for(int i=0;i<m;i++) {
        cin >> v;
        ciel.push_back(v);
        cards.insert(v);
        cnt[v]--;
    }


    int res = 0;

    sort(atk.begin(), atk.end());
    sort(ciel.begin(), ciel.end());
    int asize = atk.size(), csize = ciel.size();
    vector<vector<int>> dp(asize+1, vector<int>(csize+1, 0));
    for(int i=0;i<asize;i++)
    for(int j=0;j<csize;j++) {
        if(ciel[j] > atk[i]) dp[i+1][j+1] = dp[i][j] + ciel[j] - atk[i];
        dp[i+1][j+1] = max(dp[i+1][j+1], max(dp[i+1][j], dp[i][j+1]));
    }
    res = dp[asize][csize];

    // case when we can clear all cards:
    bool canClear = clearable();
    if(canClear) {
        // match all defense first
        for(int x : def) {
            cards.erase(cards.upper_bound(x));
        }
        int sum = accumulate(cards.begin(), cards.end(), 0);
        int atksum = accumulate(atk.begin(), atk.end(), 0);
        res = max(sum - atksum, res);
    }
    cout << res;
}
