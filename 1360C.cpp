#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,v,s;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&s);
        vector<int> vs;
        int odd = 0, even = 0;
        for(int i=0;i<s;i++) {
            scanf("%d",&v);
            vs.push_back(v);
            if(v&1) odd++;
            else even++;
        }
        sort(vs.begin(),vs.end());
        int cnt_adj = 0;
        for(int i=0;i<s-1;i++) {
            if(vs[i+1] - vs[i] == 1) cnt_adj++;
        }
        if(odd%2 && even%2 && cnt_adj) {
            odd--; even--;
        }
        if(odd%2==0 && even%2==0) cout <<"YES" << endl;
        else cout << "NO" << endl;
    }
}
