#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    int t,n,m,v;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        int tot = n+m-1;
        int half = tot/2;
        vector<int> cnt1(tot);
        vector<int> cnt0(tot);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                scanf("%d",&v);
                int idx = i+j;
                if(idx >= half) idx = (tot-1)-idx;
                if(v==1) cnt1[idx]++;
                else cnt0[idx]++;
            }
        }
        int lim = half - (tot%2);
        int res = 0;
        for(int i=0;i<=lim;i++)
            res += min(cnt0[i], cnt1[i]);
        printf("%d\n", res);
    }
}
