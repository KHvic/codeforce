#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc,n,v;
    scanf("%d",&tc);
    while(tc--) {
        map<int,int> cnt;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&v);
            cnt[v]++;
        }
        int unicnt = cnt.size();
        int res = 0;
        for(auto& p : cnt) {
            int without = min(unicnt-1, p.second);
            int with = min(unicnt, p.second-1);
            res = max(res, max(without, with));
        }
        printf("%d\n",res);
    }
}
