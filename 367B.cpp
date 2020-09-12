#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n, m, p, v;
    cin >> n >> m >> p;
    vector<int> vals(n);
    unordered_map<int, int> cnt;
    for(int i=0;i<n;i++) cin >> vals[i];
    for(int i=0;i<m;i++) {
        cin >> v;
        cnt[v]++;
    }
    vector<bool> can(n);
    vector<int> res;
    for(int i=0;i<p;i++) {
        map<int, int> cnt2;
        int invalid = 0;
        for(int j=i,k=0;j<n;j+=p,k++) {
            if(++cnt2[vals[j]] > cnt[vals[j]]) invalid++;
            if(k>=m-1) {
                int first = j-(m-1)*p;
                if(invalid == 0) can[first] = true;
                if(cnt2[vals[first]]-- > cnt[vals[first]]) invalid--;
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(can[i]) res.push_back(i+1);
    }
    cout << res.size() << "\n";
    for(int i=0;i<res.size();i++) cout << res[i] << " \n"[i==res.size()-1];
}
