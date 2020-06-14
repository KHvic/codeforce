#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    int t,n,x,m,l,r;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d",&n,&x,&m);
        int low = x, hi = x;
        for(int i=0;i<m;i++) {
            scanf("%d %d",&l,&r);
            if(r>=low && hi>=l) {
                low = min(l, low);
                hi = max(hi, r);
            }
        }
        printf("%d\n", hi-low+1);
    }
}
