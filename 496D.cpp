#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int,int> pi;
vector<int> one, two;
vector<pi> res;
int n, v;

void can(int t) {
    int t1 = t, t2 = t;
    int oneWon = 0, twoWon = 0;
    while(true) {
        // possible optimization: instead of binary search
        // we can compute pos[i] => the smallest position with t score for each player
        int nxtT1 = lower_bound(one.begin(), one.end(), t1) - one.begin();
        int nxtT2 = lower_bound(two.begin(), two.end(), t2) - two.begin();
        if(nxtT1 >n && nxtT2 >n) break;
        else if(nxtT1 < nxtT2) {
            oneWon++;
            t1 += t;
            t2 = two[nxtT1]+t;
            if(nxtT1 == n && oneWon > twoWon) {
                res.emplace_back(oneWon, t);
                break;
            }
        } else {
            twoWon++;
            t1 = one[nxtT2]+t;
            t2 += t;
            if(nxtT2 == n && twoWon > oneWon) {
                res.emplace_back(twoWon, t);
                break;
            }
        }
    }
}

int main()
{
    fastio
    cin >> n;
    one.push_back(0); two.push_back(0);
    for(int i=0;i<n;i++) {
        cin >> v;
        one.push_back(one.back() + (v==1));
        two.push_back(two.back() + (v==2));
    }
    for(int i=1;i<=n;i++) can(i);
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for(auto r : res) cout << r.first << " " << r.second << "\n";
}
