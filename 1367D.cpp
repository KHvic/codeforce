#include<bits/stdc++.h>
using namespace std;
// start allocating b with 0s => no alpha higher than it
// allocate highest alpha with same number of 0s to these spots
// update all bs based on allocated, and repeat until all are assigned

int main(){
    int tc, n, b;
    string t;
    scanf("%d",&tc);
    while(tc--) {
        cin >> t;
        scanf("%d", &n);
        vector<int> bs;
        vector<int> cnt(26);
        for(char c : t) cnt[c-'a']++;
        vector<int> zeros;
        for(int i=0;i<n;i++) {
            scanf("%d", &b);
            bs.push_back(b);
            if(!b) zeros.push_back(i);
        }
        string res(bs.size(), 'a');
        int alphaIdx = 26;
        while(!zeros.empty()) {
            int need = zeros.size();
            while(cnt[alphaIdx] < need) alphaIdx--;
            vector<int> nzeros;
            for(int x : zeros) {
                res[x] = (char)(alphaIdx + 'a');
                for(int i=0;i<bs.size();i++) {
                    if(bs[i] == 0) continue;
                    bs[i] -= abs(i-x);
                    if(bs[i] == 0) nzeros.push_back(i);
                }
            }
            alphaIdx--;
            zeros = nzeros;
        }
        cout << res << endl;
    }
}
