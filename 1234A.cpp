#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t,n,v;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        int sum = 0;
        for(int i=0;i<n;i++) {
            scanf("%d",&v);
            sum += v;
        }
        int res = (int)(ceil((double)sum/n));
        printf("%d\n",res);
    }
}
