#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,t,v;
    scanf("%d %d",&n, &t);
    int cnt_t = 0, smaller = 0, larger = 0;
    for(int i=0;i<n;i++) {
        scanf("%d",&v);
        if(v==t) cnt_t++;
        else if(v<t) smaller++;
        else larger++;
    }
    int ans = 0;
    if(cnt_t==0) {
        ans++;
        cnt_t++;
    }
    if(larger > smaller) {
        ans += max(0, larger-smaller-cnt_t);
    } else if(smaller > larger) {
        ans += max(0, smaller-larger-(cnt_t-1));
    }
    printf("%d\n",ans);
}
