#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,v;
    scanf("%d",&n);
    vector<int> vs;
    for(int i=0;i<n;i++) {
        scanf("%d",&v);
        vs.push_back(v);
    }
    sort(vs.begin(), vs.end());
    int mid=n-1;
    int ans=n;
    for(int i=n/2-1;i>=0;i--){
        if(vs[i]*2<=vs[mid]){
            ans--;
            mid--;
        }
    }
    printf("%d\n",ans);
}
