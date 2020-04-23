#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d", &n, &k);
        vector<int> vals(n);
        vector<int> onechange(k*2+2), nochange(k*2+2);
        for(int i=0;i<n;i++) scanf("%d",&vals[i]);

        for(int i=0;i<n/2;i++) {
            int l = vals[i], r = vals[n-1-i];
            nochange[l+r]++; // no change
            // range of min to max with 1 change [min(l,r)+1 : max(l,r)+k]
            onechange[max(l,r)+k+1]--;
            onechange[min(l,r)+1]++;
        }
        // prefix sum to get cumulative change needed for 1 change
        for(int i=1;i<=2*k;i++)
            onechange[i] += onechange[i-1];
        int res = n;
        for(int i=1;i<=2*k;i++) {
            int cost = onechange[i] - nochange[i]; // cost of 1 change to reach i
            cost += (n/2 - onechange[i])*2; // number of 2 change, inclusion-exclusion (exclude pairs with onechange that can reach i)
            res = min(res, cost);
        }
        printf("%d\n", res);
    }
}
