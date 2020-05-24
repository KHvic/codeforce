#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,v,s;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&s);
        vector<int> vs;
        for(int i=0;i<s;i++) {
            scanf("%d",&v);
            vs.push_back(v);
        }
        sort(vs.begin(),vs.end());
        int best = INT_MAX;
        for(int i=0;i<s-1;i++) {
            best = min(best, vs[i+1]-vs[i]);
        }
        printf("%d\n", best);
    }
}
