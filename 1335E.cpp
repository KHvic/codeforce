#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> posMap;

int maxCntNotA(int low, int high, int a) {
    int best = 0;
    for(auto& p : posMap) {
        if(p.first == a) continue;
        auto up = lower_bound(p.second.begin(), p.second.end(), high);
        auto down = lower_bound(p.second.begin(), p.second.end(), low);
        best = max(up-down, best);
    }
    return best;
}

int main(){
    int tc,n,v;
    scanf("%d",&tc);
    while(tc--) {
        posMap.clear();
        scanf("%d", &n);
        int singleMax = 0;
        for(int i=0;i<n;i++) {
            scanf("%d",&v);
            posMap[v].push_back(i);
        }
        int best = 0;
        for(auto& p : posMap) {
            singleMax = max(singleMax, (int)p.second.size());
            int low = 0, high = p.second.size()-1;
            while(low<high) {
                int posLow = p.second[low];
                int posHigh = p.second[high];
                best = max(best, maxCntNotA(posLow, posHigh, p.first) + (low+1)*2);
                low++;
                high--;
            }
        }
        best = max(singleMax, best);
        printf("%d\n", best);
    }
}
